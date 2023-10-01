/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:07:11 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/01 23:58:20 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
}

Harl::~Harl(void)
{
}

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl
		<< "Debug messages contain contextual information."
		<< " They are mostly used for problem diagnosis."
		<< std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl
		<< "Info messages contain extensive information."
		<< " They are helpful for tracing program execution in a"
		<< " production environment."
		<< std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl
		<< "Warning messages indicate a potential issue in the"
		<< " system. However, they can be handled or ignored."
		<< std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl
		<< "Error messages indicate an unrecoverable error has"
		<< " ocurred. This is usually a critical issue that requires manual"
		<< " intervention."
		<< std::endl;
}

void	Harl::complain(std::string level)
{
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	std::size_t	i = 0;

	while ((i < (sizeof(levels) / sizeof(*levels)))
		&& levels[i].compare(level))
		i++;
	switch (i)
	{
		case 0:
			this->debug();
			/* FALLTHRU */
		case 1:
			this->info();
			/* FALLTHRU */
		case 2:
			this->warning();
			/* FALLTHRU */
		case 3:
			this->error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant"
				<< " problems ]"
				<< std::endl;
	}
}
