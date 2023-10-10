/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 23:02:54 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/10 18:59:08 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void):
	ClapTrap()
{
	this->_hitPts = 100;
	this->_energyPts = 50;
	this->_damagePts = 20;
	std::cout << "[Default Constructor]: DiamondTrap " << ClapTrap::_name
		<< " has been created." << std::endl << "\t- " << this->_hitPts 
		<< " Hit Points," << std::endl << "\t- " << this->_energyPts
		<< " Energy Points," << std::endl << "\t- " << this->_damagePts
		<< " Damage Points," << std::endl
		<< "----------------------------------------------------" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name):
	ClapTrap(name)
{
	this->_hitPts = 100;
	this->_energyPts = 50;
	this->_damagePts = 20;
	std::cout << "[Constructor]: DiamondTrap " << this->_name
		<< " has been created." << std::endl << "\t- " << this->_hitPts 
		<< " Hit Points," << std::endl << "\t- " << this->_energyPts
		<< " Energy Points," << std::endl << "\t- " << this->_damagePts
		<< " Damage Points," << std::endl
		<< "----------------------------------------------------" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondTrap):
	ClapTrap(diamondTrap)
{
	std::cout << "[Copy constructor]: DiamondTrap " << this->_name 
	<< " has been created." << std::endl << "\t- " << this->_hitPts
	<< " Hit Points," << std::endl << "\t- " << this->_energyPts
	<< " Energy Points," << std::endl << "\t- " << this->_damagePts
	<< " Damage Points." << std::endl
	<< "----------------------------------------------------" << std::endl;
}

/* ******************************* DESTRUCTOR ******************************* */
DiamondTrap::~DiamondTrap(void)
{
	std::cout << "[Destructor]: DiamondTrap " << this->_name
	<< " has been destroyed." << std::endl
	<< "----------------------------------------------------" << std::endl;
}

/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
DiamondTrap&	DiamondTrap::operator=(DiamondTrap diamondTrap)
{
	return ((DiamondTrap&)ClapTrap::operator=(diamondTrap));
}

/* **************************** MEMBER FUNCTIONS **************************** */
void	DiamondTrap::guardGate(void)
{
	std::cout << "[Guard Gate]: DiamondTrap " << this->_name
	<< " is in gate keeper mode now." << std::endl
	<< "----------------------------------------------------" << std::endl;
}
