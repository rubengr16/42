/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 23:02:54 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/11 20:43:35 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void):
	ClapTrap()
{
	this->_hitPts = 100;
	this->_energyPts = 50;
	this->_damagePts = 20;
	std::cout << "[Default Constructor]: ScavTrap " << ClapTrap::_name
		<< " has been created." << std::endl << "\t- " << this->_hitPts
		<< " Hit Points," << std::endl << "\t- " << this->_energyPts
		<< " Energy Points," << std::endl << "\t- " << this->_damagePts
		<< " Damage Points," << std::endl
		<< "----------------------------------------------------" << std::endl;
}

ScavTrap::ScavTrap(std::string name):
	ClapTrap(name)
{
	this->_hitPts = 100;
	this->_energyPts = 50;
	this->_damagePts = 20;
	std::cout << "[Constructor]: ScavTrap " << this->_name
		<< " has been created." << std::endl << "\t- " << this->_hitPts
		<< " Hit Points," << std::endl << "\t- " << this->_energyPts
		<< " Energy Points," << std::endl << "\t- " << this->_damagePts
		<< " Damage Points," << std::endl
		<< "----------------------------------------------------" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& scavTrap):
	ClapTrap(scavTrap)
{
	std::cout << "[Copy constructor]: ScavTrap " << this->_name
	<< " has been created." << std::endl << "\t- " << this->_hitPts
	<< " Hit Points," << std::endl << "\t- " << this->_energyPts
	<< " Energy Points," << std::endl << "\t- " << this->_damagePts
	<< " Damage Points." << std::endl
	<< "----------------------------------------------------" << std::endl;
}

/* ******************************* DESTRUCTOR ******************************* */
ScavTrap::~ScavTrap(void)
{
	std::cout << "[Destructor]: ScavTrap " << this->_name
	<< " has been destroyed." << std::endl
	<< "----------------------------------------------------" << std::endl;
}

/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
ScavTrap&	ScavTrap::operator=(ScavTrap scavTrap)
{
	if (this == &scavTrap)
		return (*this);
	this->_name = scavTrap.getName();
	this->_hitPts = scavTrap.getHitPts();
	this->_energyPts = scavTrap.getEnergyPts();
	this->_damagePts = scavTrap.getDamagePts();
	std::cout << "[Copy assignment operator]: ScavTrap " << this->_name
		<< " has been copied." << std::endl << "\t- " << this->_hitPts
		<< " Hit Points," << std::endl << "\t- " << this->_energyPts
		<< " Energy Points," << std::endl << "\t- " << this->_damagePts
		<< " Damage Points." << std::endl
		<< "----------------------------------------------------" << std::endl;
	return (*this);
}

/* **************************** MEMBER FUNCTIONS **************************** */
unsigned int	ScavTrap::getHitPts(void) const
{
	return (this->_hitPts);
}

void	ScavTrap::setHitPts(unsigned int	hitPts)
{
	this->_hitPts = hitPts;
}

unsigned int	ScavTrap::getEnergyPts(void) const
{
	return (this->_energyPts);
}

void	ScavTrap::setEnergyPts(unsigned int	energyPts)
{
	this->_energyPts = energyPts;
}

unsigned int	ScavTrap::getDamagePts(void) const
{
	return (this->_damagePts);
}

void	ScavTrap::setDamagePts(unsigned int	damagePts)
{
	this->_damagePts = damagePts;
}

void	ScavTrap::attack(const std::string& target)
{
	if (!this->_energyPts || !this->_hitPts)
	{
		std::cout << "[Attack]: ScavTrap" << this->_name
			<< " has no points left. Attack aborted!!" << std::endl
			<< "----------------------------------------------------"
			<< std::endl;
		return ;
	}
	this->_energyPts--;
	std::cout << "[Attack]: ScavTrap " << this->_name << " attacks " << target
		<< ", causing " << this->_damagePts << " points of damage!"
		<< std::endl << "----------------------------------------------------"
		<< std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "[Guard Gate]: ScavTrap " << this->_name
	<< " is in gate keeper mode now." << std::endl
	<< "----------------------------------------------------" << std::endl;
}
