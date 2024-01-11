/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:28:41 by rgallego          #+#    #+#             */
/*   Updated: 2024/01/11 21:53:39 by rgallego         ###   ########.fr       */
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
	char				sep;

	if (str.length() != 10)
		throw (BitcoinExchange::WrongLineFormatException());
	stream >> datetime.tm_year;
	if (datetime.tm_year < -999 || 9999 < datetime.tm_year)
		throw (BitcoinExchange::WrongLineFormatException());
	stream >> sep;
	if (sep != '-')
		throw (BitcoinExchange::WrongLineFormatException());
	stream >> datetime.tm_mon;
	if (datetime.tm_mon < 1 || 12 < datetime.tm_mon)
		throw (BitcoinExchange::WrongLineFormatException());
	stream >> sep;
	if (sep != '-')
		throw (BitcoinExchange::WrongLineFormatException());
	stream >> datetime.tm_mday;
	/*
	JUST TO BE THINKED
		if (day < 1 || day > 31)
        return false;

      // Check for specific month-day combinations that are invalid
      if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;

      if (month == 2) {
        // Check for leap year
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
          if (day > 29)
            return false;
        } else {
          if (day > 28)
            return false;
        }
      }
	*/
	if (datetime.tm_mday < 1 || 31 < datetime.tm_mday)
		throw (BitcoinExchange::WrongLineFormatException());
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
