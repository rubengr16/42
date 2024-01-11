/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:28:41 by rgallego          #+#    #+#             */
/*   Updated: 2024/01/11 20:41:03 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* ****************************** CONSTRUCTORS ****************************** */
BitcoinExchange::BitcoinExchange(void)
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &rhs)
{
}

/* ******************************* DESTRUCTOR ******************************* */
BitcoinExchange::~BitcoinExchange(void)
{
}

/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs)
{
	return (*this);
}

/* **************************** MEMBER FUNCTIONS **************************** */
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
	while(!fin.eof() && std::getline(fin, line)) // TODO: REVISAR
	{
		
	}
}

void	BitcoinExchange::checkDate(std::string& str)
{
	std::stringstream	stream(str);
	std::tm				datetime;
	

	if (str.length() != 10)
		throw (BitcoinExchange::WrongLineFormatException());
	stream >> datetime.tm_year;
	stream >> datetime.tm_mon;
	stream >> datetime.tm_mday;
	
}

void	BitcoinExchange::readFormattedLine(std::string& line, std::string& sep,
	std::string& date, float& value)
{
	size_t	pos = line.find(sep);
	std::string	value = line.substr(pos + sep.length());
	date = line.substr(0, pos);
	
	// std::stringstream	s(line);
	// std::getline(s, date, sep);
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
