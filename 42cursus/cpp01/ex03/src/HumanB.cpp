/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:00:04 by rgallego          #+#    #+#             */
/*   Updated: 2023/12/02 18:26:36 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "HumanB.hpp"

HumanB::HumanB(std::string name):
	_name(name),
	_weapon(NULL)
{
}

HumanB::~HumanB(void)
{
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

void	HumanB::attack(void) const
{
	if (!this->_weapon)
	{
		std::cout << this->_name << " can't attack without weapon"
			<< std::endl;
		return ;
	}
	std::cout << this->_name
		<< " attacks with their " << this->_weapon->getType()
		<< std::endl;
}
