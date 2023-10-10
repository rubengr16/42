/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:24:36 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/09 23:13:01 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* ****************************** CONSTRUCTORS ****************************** */
ClapTrap::ClapTrap(void):
	_name("unnamed"),
	_hitPts(10),
	_energyPts(10),
	_damagePts(0)
{
	std::cout << "[Default Constructor]: ClapTrap " << this->_name
		<< " has been created." << std::endl << "\t- " << this->_hitPts 
		<< " Hit Points," << std::endl << "\t- " << this->_energyPts
		<< " Energy Points," << std::endl << "\t- " << this->_damagePts
		<< " Damage Points," << std::endl
		<< "----------------------------------------------------" << std::endl;
}

ClapTrap::ClapTrap(std::string name):
	_name(name),
	_hitPts(10),
	_energyPts(10),
	_damagePts(0)
{
	std::cout << "[Constructor]: ClapTrap " << this->_name
		<< " has been created." << std::endl << "\t- " << this->_hitPts 
		<< " Hit Points," << std::endl << "\t- " << this->_energyPts
		<< " Energy Points," << std::endl << "\t- " << this->_damagePts
		<< " Damage Points," << std::endl
		<< "----------------------------------------------------" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& clapTrap):
	_name(clapTrap.getName()),
	_hitPts(clapTrap.getHitPts()),
	_energyPts(clapTrap.getEnergyPts()),
	_damagePts(clapTrap.getDamagePts())
{
	std::cout << "[Copy constructor]: ClapTrap " << this->_name 
		<< " has been created." << std::endl << "\t- " << this->_hitPts
		<< " Hit Points," << std::endl << "\t- " << this->_energyPts
		<< " Energy Points," << std::endl << "\t- " << this->_damagePts
		<< " Damage Points." << std::endl
		<< "----------------------------------------------------" << std::endl;
}

/* ******************************* DESTRUCTOR ******************************* */
ClapTrap::~ClapTrap(void)
{
	std::cout << "[Destructor]: ClapTrap " << this->_name
		<< " has been destroyed." << std::endl
		<< "----------------------------------------------------" << std::endl;
}
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */

void	swap(ClapTrap& clapTrap1, ClapTrap& clapTrap2)
{
	std::swap(clapTrap1._name, clapTrap2._name);
	std::swap(clapTrap1._damagePts, clapTrap2._damagePts);
	std::swap(clapTrap1._energyPts, clapTrap2._energyPts);
	std::swap(clapTrap1._hitPts, clapTrap2._hitPts);
}

ClapTrap& ClapTrap::operator=(ClapTrap clapTrap)
{
	swap(*this, clapTrap);
	std::cout << "[Copy assignment operator]: ClapTrap " << this->_name
		<< " has been copied." << std::endl << "\t- " << this->_hitPts
		<< " Hit Points," << std::endl << "\t- " << this->_energyPts 
		<< " Energy Points," << std::endl << "\t- " << this->_damagePts
		<< " Damage Points." << std::endl
		<< "----------------------------------------------------" << std::endl;
	return (*this);
}
/* **************************** MEMBER FUNCTIONS **************************** */
std::string	ClapTrap::getName(void) const
{
	return (this->_name);
}

void	ClapTrap::setName(std::string name)
{
	this->_name = name;
}

unsigned int	ClapTrap::getHitPts(void) const
{
	return (this->_hitPts);
}

void	ClapTrap::setHitPts(unsigned int	hitPts)
{
	this->_hitPts = hitPts;
}

unsigned int	ClapTrap::getEnergyPts(void) const
{
	return (this->_energyPts);
}

void	ClapTrap::setEnergyPts(unsigned int	energyPts)
{
	this->_energyPts = energyPts;
}

unsigned int	ClapTrap::getDamagePts(void) const
{
	return (this->_damagePts);
}

void	ClapTrap::setDamagePts(unsigned int	damagePts)
{
	this->_damagePts = damagePts;
}

void	ClapTrap::attack(const std::string& target)
{
	if (!this->_energyPts || !this->_hitPts)
	{
		std::cout << "[Attack]: ClapTrap" << this->_name
			<< " has no points left. Attack aborted!!" << std::endl
			<< "----------------------------------------------------"
			<< std::endl;
		return ;
	}
	this->_energyPts--;
	std::cout << "[Attack]: ClapTrap " << this->_name << " attacks " << target
		<< ", causing " << this->_damagePts << " points of damage!"
		<< std::endl << "----------------------------------------------------"
		<< std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!this->_hitPts)
	{
		std::cout << "[Take Damage]: ClapTrap" << this->_name
			<< " has no points left. Take damage aborted!!" << std::endl
			<< "----------------------------------------------------"
			<< std::endl;
		return ;
	}
	if (((int)this->_hitPts - (int)amount) < 0)
		this->_hitPts = 0;
	else
		this->_hitPts -= amount;
	std::cout << "[Take Damage]: ClapTrap " << this->_name << " takes "
		<< amount << " points of damage, having " << this->_hitPts << " hit "
		<< "points left!!"
		<< std::endl << "----------------------------------------------------"
		<< std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->_energyPts || !this->_hitPts)
	{
		std::cout << "[Be Repaired]: ClapTrap " << this->_name
			<< " has no points left. Repair aborted!!" << std::endl
			<< "----------------------------------------------------"
			<< std::endl;
		return ;
	}
	this->_energyPts--;
	this->_hitPts += amount;
	std::cout << "[Attack]: ClapTrap " << this->_name << " is repaired with "
		<< amount << ". They has " << this->_hitPts << " hit points left!!"
		<< std::endl << "----------------------------------------------------"
		<< std::endl;
}
