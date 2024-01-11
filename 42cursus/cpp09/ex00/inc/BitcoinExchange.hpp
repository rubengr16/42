/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:28:41 by rgallego          #+#    #+#             */
/*   Updated: 2024/01/11 20:39:57 by rgallego         ###   ########.fr       */
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

class BitcoinExchange
{
	private:
		std::map<std::string, float>	_btcEvolution;
		void	setBtcEvolution(void);
		void	readFormattedLine(std::string& line, std::string& sep,
			std::string& date, float& value);
		void	checkDate(std::string& str);

	public:
/* ****************************** CONSTRUCTORS ****************************** */
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &rhs);
/* ******************************* DESTRUCTOR ******************************* */
		~BitcoinExchange(void);
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		BitcoinExchange& operator=(const BitcoinExchange& rhs);
/* **************************** MEMBER FUNCTIONS **************************** */
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
