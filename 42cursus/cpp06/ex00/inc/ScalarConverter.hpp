/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 23:41:15 by rgallego          #+#    #+#             */
/*   Updated: 2024/01/17 20:42:02 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <cerrno>
# include <cmath>
# include <limits>

# define PRECISION 2
# define NAN42 "nan"
# define INF "+inf"
# define NINF "-inf"
# define NANF42 "nanf"
# define INFF "+inff"
# define NINFF "-inff"
# define FT_UNDERFLOW "underflow"
# define FT_OVERFLOW "overflow"

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
		static void			toChar(char c);
		static void			toChar(int nb);
		static void			toChar(const std::string& input, float flt);
		static void			toChar(const std::string& input, double dbl);
/* *********************************** INT ********************************** */
		static int			getInt(std::string& input);
		static void			toInt(const std::string& input, int nb);
		static void			toInt(const std::string& input, float flt);
		static void			toInt(const std::string& input, double nb);
/* ********************************** FLOAT ********************************* */
		static float		getFloat(std::string& input);
		static void			toFloat(const std::string& input, float flt);
		static void			toFloat(const std::string& input, double dbl);
/* ********************************* DOUBLE ********************************* */
		static double		getDouble(std::string& input);
		static void			toDouble(const std::string& input, double dbl);

	public:
		static void			conversion(std::string& input);
};

#endif
