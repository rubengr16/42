/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:28:41 by rgallego          #+#    #+#             */
/*   Updated: 2024/01/14 23:46:08 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>	// ifstream
# include <ctime>	// tm
# include <sstream>	// stringstream
# include <map>

# define DB_FILENAME "data.csv"
# define MIN_VALUE 0.0
# define MAX_VALUE 1000.0
# define CSV_HEADER "date,exchange_rate"
# define CSV_SEP ","
# define PIPED_CSV 1
# define PIPED_CSV_HEADER "date | value"
# define PIPED_CSV_SEP " | "

class BitcoinExchange
{
	private:
		std::map<std::string, float>	_btcEvolution;
		float						checkValue(const std::string& str) const;
		void						checkDate(const std::string& str) const;
		void						readFormattedLine(std::string& line,
			std::string sep, std::string& date, float& value);
		void						displayFormatted(std::string& date,
			float value, float exchange) const;
		void						setBtcEvolution(void);

	public:
/* ****************************** CONSTRUCTORS ****************************** */
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &rhs);
/* ******************************* DESTRUCTOR ******************************* */
		~BitcoinExchange(void);
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		BitcoinExchange&				 operator=(const BitcoinExchange& rhs);
/* **************************** MEMBER FUNCTIONS **************************** */
		std::map<std::string, float>	getBtcEvolution(void) const;
		void							displayInputFile(const char* filename);
/* ******************************* EXCEPTIONS ******************************* */
	class	ABitcoinExchangeException: public std::exception
	{
		public:
			virtual const char*	what(void) const throw() = 0;
	};
	
	class	FileOpeningException: public ABitcoinExchangeException
	{
		public:
			virtual const char*	what(void) const throw();
	};

	class	WrongLineFormatException: public ABitcoinExchangeException
	{
		public:
			virtual const char*	what(void) const throw();
	};

	class	WrongDateException: public ABitcoinExchangeException
	{
		public:
			virtual const char*	what(void) const throw();
	};

	class	TooLargeNumberException: public ABitcoinExchangeException
	{
		public:
			virtual const char*	what(void) const throw();
	};

	class	NotPositiveNumberException: public ABitcoinExchangeException
	{
		public:
			virtual const char*	what(void) const throw();
	};
};

#endif
