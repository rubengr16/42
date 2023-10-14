/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 23:02:54 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/13 16:10:16 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void):
	ClapTrap()
{
	this->_hitPts = 100;
	this->_energyPts = 100;
	this->_damagePts = 30;
	std::cout << "[Default Constructor]: FragTrap " << ClapTrap::_name
		<< " has been created." << std::endl << "\t- " << this->_hitPts
		<< " Hit Points," << std::endl << "\t- " << this->_energyPts
		<< " Energy Points," << std::endl << "\t- " << this->_damagePts
		<< " Damage Points," << std::endl
		<< "----------------------------------------------------" << std::endl;
}

FragTrap::FragTrap(std::string name):
	ClapTrap(name)
{
	this->_hitPts = 100;
	this->_energyPts = 100;
	this->_damagePts = 30;
	std::cout << "[Constructor]: FragTrap " << this->_name
		<< " has been created." << std::endl << "\t- " << this->_hitPts 
		<< " Hit Points," << std::endl << "\t- " << this->_energyPts
		<< " Energy Points," << std::endl << "\t- " << this->_damagePts
		<< " Damage Points," << std::endl
		<< "----------------------------------------------------" << std::endl;
}

FragTrap::FragTrap(const FragTrap& fragTrap):
	ClapTrap(fragTrap)
{
	std::cout << "[Copy constructor]: FragTrap " << this->_name
	<< " has been created." << std::endl << "\t- " << this->_hitPts
	<< " Hit Points," << std::endl << "\t- " << this->_energyPts
	<< " Energy Points," << std::endl << "\t- " << this->_damagePts
	<< " Damage Points." << std::endl
	<< "----------------------------------------------------" << std::endl;
}

/* ******************************* DESTRUCTOR ******************************* */
FragTrap::~FragTrap(void)
{
	std::cout << "[Destructor]: FragTrap " << this->_name
	<< " has been destroyed." << std::endl
	<< "----------------------------------------------------" << std::endl;
}

/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
void	swap(FragTrap& fragTrap1, FragTrap& fragTrap2)
{
	std::swap(fragTrap1._name, fragTrap2._name);
	std::swap(fragTrap1._damagePts, fragTrap2._damagePts);
	std::swap(fragTrap1._energyPts, fragTrap2._energyPts);
	std::swap(fragTrap1._hitPts, fragTrap2._hitPts);
}

FragTrap&	FragTrap::operator=(FragTrap fragTrap)
{
	swap(*this, fragTrap);
	std::cout << "[Copy assignment operator]: FragTrap " << this->_name
		<< " has been copied." << std::endl << "\t- " << this->_hitPts
		<< " Hit Points," << std::endl << "\t- " << this->_energyPts 
		<< " Energy Points," << std::endl << "\t- " << this->_damagePts
		<< " Damage Points." << std::endl
		<< "----------------------------------------------------" << std::endl;
	return (*this);
}

/* **************************** MEMBER FUNCTIONS **************************** */
unsigned int	FragTrap::getHitPts(void) const
{
	return (this->_hitPts);
}

void	FragTrap::setHitPts(unsigned int	hitPts)
{
	this->_hitPts = hitPts;
}

unsigned int	FragTrap::getEnergyPts(void) const
{
	return (this->_energyPts);
}

void	FragTrap::setEnergyPts(unsigned int	energyPts)
{
	this->_energyPts = energyPts;
}

unsigned int	FragTrap::getDamagePts(void) const
{
	return (this->_damagePts);
}

void	FragTrap::setDamagePts(unsigned int	damagePts)
{
	this->_damagePts = damagePts;
}

void	FragTrap::highFiveGuys(void)
{
	std::cout << "[High Five Guys]: FragTrap " << this->_name
		<< " high fives y'all! Nice to see you!!." << std::endl
		<< "----------------------------------------------------" << std::endl;
}
