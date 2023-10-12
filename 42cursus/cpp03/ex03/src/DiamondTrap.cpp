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
	ClapTrap("unnamed_clap_name"), FragTrap(), ScavTrap()
{
	this->_name = "unnamed";
	this->_hitPts = this->FragTrap::_hitPts;
	this->_energyPts = this->ScavTrap::_energyPts;
	this->_damagePts = this->FragTrap::_damagePts;
	std::cout << "[Default Constructor]: DiamondTrap " << this->_name
		<< ", known as Claptrap " << this->ClapTrap::_name
		<< ", has been created." << std::endl << "\t- " << this->_hitPts
		<< " Hit Points," << std::endl << "\t- " << this->_energyPts
		<< " Energy Points," << std::endl << "\t- " << this->_damagePts
		<< " Damage Points," << std::endl
		<< "----------------------------------------------------" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name):
	ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap()
{
	this->_name = name;
	this->_hitPts = this->FragTrap::_hitPts;
	this->_energyPts = this->ScavTrap::_energyPts;
	this->_damagePts = this->FragTrap::_damagePts;
	std::cout << "[Constructor]: DiamondTrap " << this->_name
		<< ", known as Claptrap " << this->ClapTrap::_name
		<< ", has been created." << std::endl << "\t- " << this->_hitPts
		<< " Hit Points," << std::endl << "\t- " << this->_energyPts
		<< " Energy Points," << std::endl << "\t- " << this->_damagePts
		<< " Damage Points," << std::endl
		<< "----------------------------------------------------" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondTrap):
	ClapTrap(diamondTrap._name + "_clap_name"), FragTrap(), ScavTrap()
{
	this->_name = diamondTrap._name;
	this->_hitPts = diamondTrap.FragTrap::getHitPts();
	this->_energyPts = diamondTrap.ScavTrap::getEnergyPts();
	this->_damagePts = diamondTrap.FragTrap::getDamagePts();
	std::cout << "[Copy constructor]: DiamondTrap " << this->_name
		<< ", known as Claptrap " << this->ClapTrap::_name
		<< ", has been created." << std::endl << "\t- " << this->_hitPts
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
void	swap(DiamondTrap& diamondTrap1, DiamondTrap& diamondTrap2)
{
	std::swap(diamondTrap1.ClapTrap::_name, diamondTrap2.ClapTrap::_name);
	std::swap(diamondTrap1._name, diamondTrap2._name);
	std::swap(diamondTrap1._damagePts, diamondTrap2._damagePts);
	std::swap(diamondTrap1._energyPts, diamondTrap2._energyPts);
	std::swap(diamondTrap1._hitPts, diamondTrap2._hitPts);
}

DiamondTrap&	DiamondTrap::operator=(DiamondTrap diamondTrap)
{
	swap(*this, diamondTrap);
	std::cout << "[Copy assignment operator]: DiamondTrap " << this->_name
		<< ", known as Claptrap " << this->ClapTrap::_name
		<< " has been copied." << std::endl << "\t- " << this->_hitPts
		<< " Hit Points," << std::endl << "\t- " << this->_energyPts 
		<< " Energy Points," << std::endl << "\t- " << this->_damagePts
		<< " Damage Points." << std::endl
		<< "----------------------------------------------------" << std::endl;
	return (*this);
}

/* **************************** MEMBER FUNCTIONS **************************** */
std::string	DiamondTrap::getName(void) const
{
	return (this->DiamondTrap::_name);
}

void	DiamondTrap::setName(std::string name)
{
	this->_name = name;
	this->ClapTrap::_name = this->_name + "_clap_name";
}

void	DiamondTrap::WhoAmI(void)
{
	std::cout << "[Who Am I]: DiamondTrap " << this->_name
	<< " says hi, they is also known as " << this->ClapTrap::_name << std::endl
	<< "----------------------------------------------------" << std::endl;
}
