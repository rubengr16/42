/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:32:24 by rgallego          #+#    #+#             */
/*   Updated: 2023/12/14 21:15:26 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	this->_name = "unnamedZombie";
	std::cout << this->_name << ": I have been born."
		<< std::endl;
}

Zombie::Zombie(std::string name)
{
	this->_name = name;
	std::cout << this->_name << ": I have been born."
		<< std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << this->_name << ": I'm dying. RIP."
		<< std::endl;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}

const std::string&	Zombie::getName(void) const
{
	return (this->_name);
}


void	Zombie::announce(void) const
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..."
		<< std::endl;
}
