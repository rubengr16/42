/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:32:24 by rgallego          #+#    #+#             */
/*   Updated: 2023/09/29 16:07:47 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "unnamedZombie" << ": I have been born."
		<< std::endl;
}

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << this->name << ": I have been born."
		<< std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << this->name << ": I'm dying. RIP."
		<< std::endl;
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}

std::string	Zombie::getName(void)
{
	return (this->name);
}


void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..."
		<< std::endl;
}
