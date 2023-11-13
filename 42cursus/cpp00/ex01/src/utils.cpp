/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 00:02:04 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/25 17:32:10 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

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
	if (field.length() > 10)
		return (field.substr(0, 9) + '.');
	return (field);
}
