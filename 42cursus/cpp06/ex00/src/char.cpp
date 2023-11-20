/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:01:56 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/20 21:39:12 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* ********************************** CHAR ********************************** */
void	ScalarConverter::toChar(char c)
{
	std::cout << "char: ";
	if (c < 0)
		std::cout << "impossible" << std::endl;
	else if (!isprint(c))
		std::cout << "non displayable" << std::endl;
	else
		std::cout << c << std::endl;
}

void	ScalarConverter::toChar(int nb)
{
	std::cout << "char: ";
	if (nb < 0 || nb > 127)
		std::cout << "impossible" << std::endl;
	else if (!isprint(nb))
		std::cout << "non displayable" << std::endl;
	else
		std::cout << static_cast<char>(nb) << std::endl;
}
void	ScalarConverter::toChar(const std::string& input, float flt)
{
	std::cout << "char: ";
	if (flt < 0 || flt > 127 || !input.compare(NANF42) || !input.compare(INFF)
		|| !input.compare(NINFF))
		std::cout << "impossible" << std::endl;
	else if (!isprint(flt))
		std::cout << "non displayable" << std::endl;
	else
		std::cout << static_cast<char>(flt) << std::endl;
}

void	ScalarConverter::toChar(const std::string& input, double dbl)
{
	std::cout << "char: ";
	if (dbl < 0 || dbl > 127 || !input.compare(NAN42) || !input.compare(INF)
		|| !input.compare(NINF))
		std::cout << "impossible" << std::endl;
	else if (!isprint(dbl))
		std::cout << "non displayable" << std::endl;
	else
		std::cout << static_cast<char>(dbl) << std::endl;
}
