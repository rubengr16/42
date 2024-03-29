/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 23:41:21 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/20 23:15:40 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* ****************************** CONSTRUCTORS ****************************** */
ScalarConverter::ScalarConverter(void)
{
	std::cout << "[Default Constructor] ScalarConverter: shall never be used"
	<< std::endl << "----------------------------------------------------"
	<< std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& scalarConverter)
{
	(void)scalarConverter;
	std::cout << "[Copy Constructor] ScalarConverter: shall never be used"
	<< std::endl << "----------------------------------------------------"
	<< std::endl;
}

/* ******************************* DESTRUCTOR ******************************* */
ScalarConverter::~ScalarConverter()
{
	std::cout << "[Destructor] ScalarConverter: shall never be used"
	<< std::endl << "----------------------------------------------------"
	<< std::endl;
}

/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
ScalarConverter&	ScalarConverter::operator=(
	const ScalarConverter& scalarConverter)
{
	(void)scalarConverter;
	std::cout << "[Copy Assignment Operator] ScalarConverter: shall never be "
	" used" << std::endl
	<< "----------------------------------------------------" << std::endl;
	return (*this);
}

/* **************************** MEMBER FUNCTIONS **************************** */
e_scalarType		ScalarConverter::getScalarType(const std::string& input)
{
	unsigned int	i = 0;
	unsigned int	point = 0;
	unsigned int	len = input.length();

	if (len == 1 && !isdigit(input[0]))
		return (CHAR);
	while (i < len && (isdigit(input[i]) || input[i] == '.') && point <= 1)
	{
		if (input[i] == '.')
			point++;
		i++;
	}
	if (i == len && !point)
		return (INT);
	if ((i == (len - 1) && input[i] == 'f' && point <= 1)
		|| !input.compare(NANF42) || !input.compare(INFF)
		|| !input.compare(NINFF))
		return (FLOAT);
	if ((i == len && point <= 1) || !input.compare(NAN42)
		|| !input.compare(INF) || !input.compare(NINF))
		return (DOUBLE);
	return (IMPOSSIBLE);
}

void	ScalarConverter::conversion(std::string& input)
{
	e_scalarType	type = getScalarType(input);
	char			c;
	int				nb;
	float			flt;
	double			dbl;

	if (type == CHAR)
	{
		c = input[0];
		toChar(c);
		toInt(input, c);
		toFloat(input, static_cast<float>(c));
		toDouble(input, c);
	}
	else if (type == INT)
	{
		nb = getInt(input);
		toChar(nb);
		toInt(input, nb);
		toFloat(input, static_cast<float>(nb));
		toDouble(input, nb);
	}
	else if (type == FLOAT)
	{
		flt = getFloat(input);
		toChar(input, flt);
		toInt(input, flt);
		toFloat(input, flt);
		toDouble(input, flt);
	}
	else if (type == DOUBLE)
	{
		dbl = getDouble(input);
		toChar(input, dbl);
		toInt(input, dbl);
		toFloat(input, dbl);
		toDouble(input, dbl);
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}
