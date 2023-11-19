/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 23:41:15 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/19 18:16:23 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

# define NAN "nan"
# define INF "+inf"
# define NINF "+inf"
# define NANF "nanf"
# define INFF "+inff"
# define NINFF "-inff"

enum e_scalarType
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	IMPOSSIBLE
};

class ScalarConverter
{
	private:
/* ****************************** CONSTRUCTORS ****************************** */
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& scalarConverter);
/* ******************************* DESTRUCTOR ******************************* */
		~ScalarConverter(void);
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		ScalarConverter&	operator=(const ScalarConverter& scalarConverter);
/* **************************** MEMBER FUNCTIONS **************************** */
		static e_scalarType	getScalarType(const std::string& input);
/* ********************************** CHAR ********************************** */
		static void	toChar(const std::string& input, char c);
		static void	toChar(const std::string& input, int nb);
		static void	toChar(const std::string& input, float flt);
		static void	toChar(const std::string& input, double dbl);
/* *********************************** INT ********************************** */
		static void	toInt(const std::string& input, char c);
		static void	toInt(const std::string& input, int nb);
		static void	toInt(const std::string& input, float flt);
		static void	toInt(const std::string& input, double dbl);
/* ********************************** FLOAT ********************************* */
		static void	toFloat(const std::string& input, char c);
		static void	toFloat(const std::string& input, int nb);
		static void	toFloat(const std::string& input, float flt);
		static void	toFloat(const std::string& input, double dbl);
/* ********************************* DOUBLE ********************************* */
		static void	toDouble(char c);
		// static double	toDouble(const std::string& input, int nb);
		// static double	toDouble(const std::string& input, float flt);
		static void	toDouble(const std::string& input, double dbl);

	public:
		static void			conversion(const std::string& input);
};

#endif
