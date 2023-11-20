/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:02:28 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/20 23:15:09 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* ********************************** FLOAT ********************************* */
float	ScalarConverter::getFloat(std::string& input)
{
	char	*endptr = NULL;
	double dbl = strtod(input.c_str(), &endptr);

	if ((errno == ERANGE && dbl == -HUGE_VAL)
		|| dbl < -std::numeric_limits<float>::max())
	{
		input = UNDERFLOW;
		return (-std::numeric_limits<float>::max());
	}
	else if ((errno == ERANGE && dbl == HUGE_VAL)
		|| dbl > std::numeric_limits<float>::max())
	{
		input = OVERFLOW;
		return (std::numeric_limits<float>::max());
	}
	return (static_cast<float>(dbl));
}

void	ScalarConverter::toFloat(const std::string& input, float flt)
{
	std::cout << "float: ";
	if (!input.compare(UNDERFLOW) || !input.compare(OVERFLOW))
		std::cout << input << std::endl;
	else if(!input.compare(NANF42) || !input.compare(INFF)
		|| !input.compare(NINFF))
		std::cout << input << std::endl;
	else if (!input.compare(NAN42) || !input.compare(INF)
		|| !input.compare(NINF))
		std::cout << input << "f" << std::endl;
	else
		std::cout << std::setprecision(PRECISION) << std::fixed
			<< flt << "f" << std::endl;
}

void	ScalarConverter::toFloat(const std::string& input, double dbl)
{
	std::cout << "float: ";
	if (!input.compare(NAN42) || !input.compare(INF)
		|| !input.compare(NINF))
		std::cout << input << "f" << std::endl;
	else if (dbl < -std::numeric_limits<float>::max())
		std::cout << UNDERFLOW << std::endl;
	else if (dbl > std::numeric_limits<float>::max())
		std::cout << OVERFLOW << std::endl;
	else
		std::cout << std::setprecision(PRECISION) << std::fixed
			<< static_cast<float>(dbl) << "f" << std::endl;
}
