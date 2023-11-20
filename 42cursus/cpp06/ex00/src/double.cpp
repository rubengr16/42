/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:02:45 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/20 21:53:43 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* ********************************* DOUBLE ********************************* */
double	ScalarConverter::getDouble(std::string& input)
{
	char	*endptr = NULL;
	double dbl = strtod(input.c_str(), &endptr);

	if ((errno == ERANGE && dbl == -HUGE_VAL))
	{
		input = UNDERFLOW;
		return (-std::numeric_limits<double>::max());
	}
	else if ((errno == ERANGE && dbl == HUGE_VAL))
	{
		input = OVERFLOW;
		return (std::numeric_limits<double>::max());
	}
	return (dbl);
}

void	ScalarConverter::toDouble(const std::string& input, double dbl)
{
	std::cout << "double: ";
	if (!input.compare(NAN42) || !input.compare(INF) || !input.compare(NINF))
		std::cout << input << std::endl;
	else if(!input.compare(NANF42) || !input.compare(INFF)
		|| !input.compare(NINFF))
		std::cout << input.substr(0, input.length() - 1) << std::endl;
	else
		std::cout << std::setprecision(PRECISION) << std::fixed
			<< dbl << std::endl;
}
