/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:01:56 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/20 01:10:19 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* ********************************** CHAR ********************************** */
void	ScalarConverter::toChar(const std::string& input, double dbl)
{
	std::cout << "char: ";
	if (!input.compare(NAN42) || !input.compare(INF) || !input.compare(NINF)
		|| !input.compare(NANF42) || !input.compare(INFF)
		|| !input.compare(NINFF))
		std::cout << "impossible" << std::endl;
}
