/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:02:45 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/19 18:20:52 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* ********************************* DOUBLE ********************************* */
void	ScalarConverter::toDouble(char c)
{
	std::cout << "double: " << static_cast<double>(c);
}

// double	ScalarConverter::toDouble(const std::string& input, int nb)
// {
// 	return (nb);
// }

// double	ScalarConverter::toDouble(const std::string& input, float flt)
// {
// 	return (flt);
// }

void	ScalarConverter::toDouble(const std::string& input, double dbl)
{
	std::cout << "double: ";
	if (!input.compare(NAN) || !input.compare(INF) || !input.compare(NINF)
		|| !input.compare(NANF) || !input.compare(INFF)
		|| !input.compare(NINFF))
		std::cout << input << std::endl;
	else
		std::cout << dbl;
}
