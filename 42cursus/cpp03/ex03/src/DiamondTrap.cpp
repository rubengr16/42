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
	this->ClapTrap::_hitPts = this->FragTrap::getHitPts();
	this->ClapTrap::_energyPts = this->ScavTrap::getEnergyPts();
	this->ClapTrap::_damagePts = this->FragTrap::getDamagePts();
	std::cout << "[Default Constructor]: DiamondTrap " << this->_name
		<< ", known as Claptrap " << this->ClapTrap::_name
		<< ", has been created." << std::endl << "\t- " << this->ClapTrap::_hitPts
		<< " Hit Points," << std::endl << "\t- " << this->ClapTrap::_energyPts
		<< " Energy Points," << std::endl << "\t- " << this->ClapTrap::_damagePts
		<< " Damage Points," << std::endl
		<< "----------------------------------------------------" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name):
	ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap()
{
	this->_name = name;
	this->ClapTrap::_hitPts = this->FragTrap::getHitPts();
	this->ClapTrap::_energyPts = this->ScavTrap::getEnergyPts();
	this->ClapTrap::_damagePts = this->FragTrap::getDamagePts();
	std::cout << "[Constructor]: DiamondTrap " << this->_name
		<< ", known as Claptrap " << this->ClapTrap::_name
		<< ", has been created." << std::endl << "\t- " << this->ClapTrap::_hitPts
		<< " Hit Points," << std::endl << "\t- " << this->ClapTrap::_energyPts
		<< " Energy Points," << std::endl << "\t- " << this->ClapTrap::_damagePts
		<< " Damage Points," << std::endl
		<< "----------------------------------------------------" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondTrap):
	ClapTrap(diamondTrap._name + "_clap_name"), FragTrap(), ScavTrap()
{
	this->_name = diamondTrap._name;
	this->ClapTrap::_hitPts = diamondTrap.FragTrap::getHitPts();
	this->ClapTrap::_energyPts = diamondTrap.ScavTrap::getEnergyPts();
	this->ClapTrap::_damagePts = diamondTrap.FragTrap::getDamagePts();
	std::cout << "[Copy constructor]: DiamondTrap " << this->_name
		<< ", known as Claptrap " << this->ClapTrap::_name
		<< ", has been created." << std::endl << "\t- " << this->ClapTrap::_hitPts
		<< " Hit Points," << std::endl << "\t- " << this->ClapTrap::_energyPts
		<< " Energy Points," << std::endl << "\t- " << this->ClapTrap::_damagePts
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
	if (this == &diamondTrap)
		return (*this);
	this->ClapTrap::_name = diamondTrap.getName();
	this->_name = diamondTrap.getClapName();
	this->ClapTrap::_hitPts = diamondTrap.getHitPts();
	this->ClapTrap::_energyPts = diamondTrap.getEnergyPts();
	this->ClapTrap::_damagePts = diamondTrap.getDamagePts();
	std::cout << "[Copy assignment operator]: DiamondTrap " << this->_name
		<< ", known as Claptrap " << this->ClapTrap::_name
		<< " has been copied." << std::endl << "\t- " << this->ClapTrap::_hitPts
		<< " Hit Points," << std::endl << "\t- " << this->ClapTrap::_energyPts 
		<< " Energy Points," << std::endl << "\t- " << this->ClapTrap::_damagePts
		<< " Damage Points." << std::endl
		<< "----------------------------------------------------" << std::endl;
	return (*this);
}

/* **************************** MEMBER FUNCTIONS **************************** */
const std::string&	DiamondTrap::getName(void) const
{
	return (this->DiamondTrap::_name);
}

const std::string&	DiamondTrap::getClapName(void) const
{
	return (this->ClapTrap::_name);
}

void	DiamondTrap::setName(std::string name)
{
	this->_name = name;
	this->ClapTrap::_name = this->_name + "_clap_name";
}

unsigned int	DiamondTrap::getHitPts(void) const
{
	return (this->ClapTrap::_hitPts);
}

void	DiamondTrap::setHitPts(unsigned int	hitPts)
{
	this->ClapTrap::_hitPts = hitPts;
}

unsigned int	DiamondTrap::getEnergyPts(void) const
{
	return (this->ClapTrap::_energyPts);
}

void	DiamondTrap::setEnergyPts(unsigned int	energyPts)
{
	this->ClapTrap::_energyPts = energyPts;
}

unsigned int	DiamondTrap::getDamagePts(void) const
{
	return (this->ClapTrap::_damagePts);
}

void	DiamondTrap::setDamagePts(unsigned int	damagePts)
{
	this->ClapTrap::_damagePts = damagePts;
}

void	DiamondTrap::WhoAmI(void)
{
	std::cout << "[Who Am I]: DiamondTrap " << this->_name
	<< " says hi, they is also known as " << this->ClapTrap::_name << std::endl
	<< "----------------------------------------------------" << std::endl;
}
