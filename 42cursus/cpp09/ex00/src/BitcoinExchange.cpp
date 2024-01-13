/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:28:41 by rgallego          #+#    #+#             */
/*   Updated: 2024/01/13 23:23:31 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* ****************************** CONSTRUCTORS ****************************** */
BitcoinExchange::BitcoinExchange(void)
{
	this->setBtcEvolution(CSV_HEADER);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &rhs)
{
	this->_btcEvolution = rhs.getBtcEvolution();
}

/* ******************************* DESTRUCTOR ******************************* */
BitcoinExchange::~BitcoinExchange(void)
{
}

/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs)
{
	if (this == &rhs)
		return (*this);
	this->_btcEvolution = rhs.getBtcEvolution();
	return (*this);
}

/* **************************** MEMBER FUNCTIONS **************************** */
std::map<std::string, float>	BitcoinExchange::getBtcEvolution(void) const
{
	return this->_btcEvolution;
}

void	BitcoinExchange::setBtcEvolution(std::string header)
{
	std::ifstream	fin;
	std::string		line;
	std::string		date;
	float			value;

	fin.open(DB_FILENAME, std::ifstream::in);
	if (!fin.is_open())
		throw (BitcoinExchange::FileOpeningException());
	std::getline(fin, line);
	if (line != header)
		throw(BitcoinExchange::WrongLineFormatException());
	while(!fin.eof() && std::getline(fin, line))
	{
		this->readFormattedLine(line, CSV_SEP, date, value);
		this->_btcEvolution.insert(std::pair<std::string, float>(date, value));
	}
}

void	BitcoinExchange::checkDate(std::string& str)
{
	std::stringstream	stream(str);
	std::tm				dt;
	char				sep;

	if (str.length() != 10)
		throw (BitcoinExchange::WrongLineFormatException());
	stream >> dt.tm_year;
	if (dt.tm_year < -999 || 9999 < dt.tm_year)
		throw (BitcoinExchange::WrongLineFormatException());
	stream >> sep;
	if (sep != '-')
		throw (BitcoinExchange::WrongLineFormatException());
	stream >> dt.tm_mon;
	if (dt.tm_mon < 1 || 12 < dt.tm_mon)
		throw (BitcoinExchange::WrongLineFormatException());
	stream >> sep;
	if (sep != '-')
		throw (BitcoinExchange::WrongLineFormatException());
	stream >> dt.tm_mday;
	if (!stream.eof() || dt.tm_mday < 1 || 31 < dt.tm_mday
		|| ((dt.tm_mon == 4 || dt.tm_mon == 6 || dt.tm_mon == 9 || dt.tm_mon == 11)
			&& (30 < dt.tm_mday))
		|| (dt.tm_mon == 2 && 29 < dt.tm_mday)
		|| (dt.tm_mon == 2 && dt.tm_year % 4 && 28 < dt.tm_mday))
		throw (BitcoinExchange::WrongLineFormatException());
}

void	BitcoinExchange::readFormattedLine(std::string& line, std::string sep,
	std::string& date, float value)
{
	size_t	pos = line.find(sep);
	std::string	value = line.substr(pos + sep.length());
	date = line.substr(0, pos);
	this->checkDate(date);
}

void	BitcoinExchange::displayInputFile(const char* filename) const
{
	std::ifstream	fin;
	std::string		line;
	std::string		date;
	float			value;

	fin.open(filename, std::ifstream::in);
	if (!fin.is_open())
		throw (BitcoinExchange::FileOpeningException());
	std::getline(fin, line);
	if (line != header)
		throw(BitcoinExchange::WrongLineFormatException());
	fin.open(fin, std::ifstream::in);
	
}

/* ******************************* EXCEPTIONS ******************************* */
const char*	BitcoinExchange::FileOpeningException::what(void) const throw()
{
	return ("There was an error managing your file."
			"Please, check if it exists, its permissions, etc.");
}

const char*	BitcoinExchange::WrongLineFormatException::what(void) const throw()
{
	return ("There was an incorrect format on a line");
}
