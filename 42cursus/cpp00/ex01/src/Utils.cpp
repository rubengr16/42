/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 00:02:04 by rgallego          #+#    #+#             */
/*   Updated: 2023/09/21 11:02:09 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

std::string	getField(std::string message)
{
	std::string	str;

	do
	{
		std::cout << message;
		std::getline(std::cin, str);
		if (str.empty())
			std::cout << "Empty input is not allowed. Please try again!"
				<< std::endl;
	} while (str.empty());
	return (str);
}

std::string	formatField(std::string field)
{
	if (10 <= field.length())
	{
		field[9] = '.';
		field[10] = '\0';
	}
	return (field);
}
