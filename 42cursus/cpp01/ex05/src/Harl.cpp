/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:07:11 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/01 17:41:27 by rgallego         ###   ########.fr       */
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
	std::cout << "DEBUG: Debug messages contain contextual information."
		<< " They are mostly used for problem diagnosis."
		<< std::endl;
}

void	Harl::info(void)
{
	std::cout << "INFO: Info messages contain extensive information."
		<< " They are helpful for tracing program execution in a"
		<< " production environment."
		<< std::endl;
}

void	Harl::warning(void)
{
	std::cout << "WARNING: Warning messages indicate a potential issue in the"
		<< " system. However, they can be handled or ignored."
		<< std::endl;
}

void	Harl::error(void)
{
	std::cout << "ERROR: Werror messages indicate an unrecoverable error has"
		<< " ocurred. This is usually a critical issue that requires manual"
		<< " intervention."
		<< std::endl;
}

void	Harl::complain(std::string level)
{
	void		(Harl::*harlLevels[4])(void) = {&Harl::debug, &Harl::info,
		&Harl::warning, &Harl::error};
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	std::size_t	i = 0;

	while (i <= levels->length() && levels[i].compare(level))
		i++;
	if (i <= levels->length())
		(this->*harlLevels[i])();
	else
		std::cout << level << ": Level not found."
			<< std::endl;
}
