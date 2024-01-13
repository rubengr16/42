/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:28:41 by rgallego          #+#    #+#             */
/*   Updated: 2024/01/13 23:23:26 by rgallego         ###   ########.fr       */
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
# define CSV_HEADER "date,exchange_rate"
# define CSV_SEP ","
# define PIPED_CSV 1
# define PIPED_CSV_HEADER "date | value"
# define PIPED_CSV_SEP " | "

class BitcoinExchange
{
	private:
		std::map<std::string, float>	_btcEvolution;
		void						checkDate(std::string& str);
		void						readFormattedLine(std::string& line,
			std::string sep, std::string& date, float value);
		void						setBtcEvolution(std::string header);

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
		void							displayInputFile(const char* filename)
			const;
/* ******************************* EXCEPTIONS ******************************* */
	class	FileOpeningException: public std::exception
	{
		public:
			virtual const char*	what(void) const throw();
	};

	class	WrongLineFormatException: public std::exception
	{
		public:
			virtual const char*	what(void) const throw();
	};
};

#endif
