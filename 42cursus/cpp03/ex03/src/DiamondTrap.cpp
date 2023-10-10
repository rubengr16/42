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
	ScavTrap(), FragTrap()
{
	this->_name = "unnamed";
	this->ClapTrap::_name = this->_name.append("_clap_name");
	this->_hitPts = FragTrap::_hitPts;
	this->_energyPts = ScavTrap::_energyPts;
	this->_damagePts = FragTrap::_damagePts;
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
		<< " says hi, they is also known as " << this->ClapTrap::_name << std::endl
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
	// TODO
	return (*this);
}

/* **************************** MEMBER FUNCTIONS **************************** */
void	DiamondTrap::WhoAmI(void)
{
	std::cout << "[Who Am I]: DiamondTrap " << this->_name
	<< " says hi, they is also known as " << this->ClapTrap::_name << std::endl
	<< "----------------------------------------------------" << std::endl;
}
