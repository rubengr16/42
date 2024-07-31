/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:02:28 by rgallego          #+#    #+#             */
/*   Updated: 2024/07/31 16:36:02 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* ********************************** FLOAT ********************************* */
float	ScalarConverter::getFloat(std::string& input)
{
	char	*endptr = NULL;
	double dbl = strtod(input.c_str(), &endptr);

	if ((errno == ERANGE && dbl == -HUGE_VALF)
		|| dbl < -std::numeric_limits<float>::max())
	{
		input = FT_UNDERFLOW;
		return (-std::numeric_limits<float>::max());
	}
	else if ((errno == ERANGE && dbl == HUGE_VALF)
		|| dbl > std::numeric_limits<float>::max())
	{
		input = FT_OVERFLOW;
		return (std::numeric_limits<float>::max());
	}
	return (static_cast<float>(dbl));
}

void	ScalarConverter::toFloat(const std::string& input, float flt)
{
	std::cout << "float: ";
	if (!input.compare(FT_UNDERFLOW) || !input.compare(FT_OVERFLOW))
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
		std::cout << FT_UNDERFLOW << std::endl;
	else if (dbl > std::numeric_limits<float>::max())
		std::cout << FT_OVERFLOW << std::endl;
	else
		std::cout << std::setprecision(PRECISION) << std::fixed
			<< static_cast<float>(dbl) << "f" << std::endl;
}
