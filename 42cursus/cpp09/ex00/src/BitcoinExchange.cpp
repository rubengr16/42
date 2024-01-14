/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:28:41 by rgallego          #+#    #+#             */
/*   Updated: 2024/01/14 15:25:16 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* ****************************** CONSTRUCTORS ****************************** */
BitcoinExchange::BitcoinExchange(void)
{
	this->setBtcEvolution();
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

void	BitcoinExchange::setBtcEvolution(void)
{
	std::ifstream	fin;
	std::string		line;
	std::string		date;
	float			value;

	fin.open(DB_FILENAME, std::ifstream::in);
	if (!fin.is_open())
		throw (BitcoinExchange::FileOpeningException());
	std::getline(fin, line);
	if (line != CSV_HEADER)
		throw(BitcoinExchange::WrongHeaderFormatException());
	while(!fin.eof() && std::getline(fin, line))
	{
		this->readFormattedLine(line, CSV_SEP, date, value);
		this->_btcEvolution.insert(std::pair<std::string, float>(date, value));
	}
}

float	BitcoinExchange::checkValue(const std::string& str) const
{
	std::stringstream	stream(str);
	float				value;

	stream >> value;
	if (value < MIN_VALUE)
		throw (BitcoinExchange::NotPositiveNumberException());
	if (MAX_VALUE < value)
		throw (BitcoinExchange::TooLargeNumberException());
	return value;
}

void	BitcoinExchange::checkDate(const std::string& str) const
{
	std::stringstream	stream(str);
	std::tm				dt;
	char				sep;

	if (str.length() != 10)
		throw (BitcoinExchange::WrongDateException());
	stream >> dt.tm_year;
	if (dt.tm_year < -999 || 9999 < dt.tm_year)
		throw (BitcoinExchange::WrongDateException());
	stream >> sep;
	if (sep != '-')
		throw (BitcoinExchange::WrongDateException());
	stream >> dt.tm_mon;
	if (dt.tm_mon < 1 || 12 < dt.tm_mon)
		throw (BitcoinExchange::WrongDateException());
	stream >> sep;
	if (sep != '-')
		throw (BitcoinExchange::WrongDateException());
	stream >> dt.tm_mday;
	if (!stream.eof() || dt.tm_mday < 1 || 31 < dt.tm_mday
		|| ((dt.tm_mon == 4 || dt.tm_mon == 6 || dt.tm_mon == 9 || dt.tm_mon == 11)
			&& (30 < dt.tm_mday))
		|| (dt.tm_mon == 2 && 29 < dt.tm_mday)
		|| (dt.tm_mon == 2 && dt.tm_year % 4 && 28 < dt.tm_mday))
		throw (BitcoinExchange::WrongDateException());
}

void	BitcoinExchange::readFormattedLine(std::string& line, std::string sep,
	std::string& date, float value)
{
	size_t	pos = line.find(sep);
	value = this->checkValue(line.substr(pos + sep.length()));
	date = line.substr(0, pos);
	this->checkDate(date);
}

void	BitcoinExchange::displayInputFile(const char* filename)
{
	std::ifstream	fin;
	std::string		line;
	std::string		date;
	float			value;

	fin.open(filename, std::ifstream::in);
	if (!fin.is_open())
		throw (BitcoinExchange::FileOpeningException());
	std::getline(fin, line);
	if (line != PIPED_CSV_HEADER)
		throw(BitcoinExchange::WrongHeaderFormatException());
	while(!fin.eof() && std::getline(fin, line))
	{
		try
		{
			this->readFormattedLine(line, PIPED_CSV_SEP, date, value);
		}
		catch(const BitcoinExchange::WrongDateException& e)
		{
			std::cerr << e.what() << " => " << date << std::endl;
		}
		catch(const BitcoinExchange::ABitcoinExchangeException& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}

/* ******************************* EXCEPTIONS ******************************* */
const char*	BitcoinExchange::FileOpeningException::what(void) const throw()
{
	return ("Error: could not open the file.");
}

const char*	BitcoinExchange::WrongHeaderFormatException::what(void) const throw()
{
	return ("Error: bad input");
}

const char*	BitcoinExchange::WrongDateException::what(void) const throw()
{
	return ("Error: bad input");
}

const char*	BitcoinExchange::TooLargeNumberException::what(void) const throw()
{
	return ("Error: too large number.");
}

const char*	BitcoinExchange::NotPositiveNumberException::what(void) const throw()
{
	return ("Error: not a positive number.");
}
