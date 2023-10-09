/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:24:36 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/09 19:14:46 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void	swap(ClapTrap& clapTrap1, ClapTrap& clapTrap2)
{
	std::swap(clapTrap1._name, clapTrap2._name);
	std::swap(clapTrap1._damagePts, clapTrap2._damagePts);
	std::swap(clapTrap1._energyPts, clapTrap2._energyPts);
	std::swap(clapTrap1._hitPts, clapTrap2._hitPts);
}

/* ****************************** CONSTRUCTORS ****************************** */
ClapTrap::ClapTrap(std::string name):
	_name(name),
	_hitPts(10),
	_energyPts(10),
	_damagePts(0)
{
	std::cout << "[Constructor]: " << this->_name << " has been created."
		<< std::endl << "\t- " << this->_hitPts << " Hit Points,"
		<< std::endl << "\t- " << this->_energyPts << " Energy Points,"
		<< std::endl << "\t- " << this->_damagePts << " Damage Points,"
		<< std::endl << "----------------------------------------------------"
		<< std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& clapTrap):
	_name(clapTrap.getName()),
	_hitPts(clapTrap.getHitPts()),
	_energyPts(clapTrap.getEnergyPts()),
	_damagePts(clapTrap.getDamagePts())
{
	std::cout << "[Copy constructor]: " << this->_name << " has been created."
		<< std::endl << "\t- " << this->_hitPts << " Hit Points,"
		<< std::endl << "\t- " << this->_energyPts << " Energy Points,"
		<< std::endl << "\t- " << this->_damagePts << " Damage Points."
		<< std::endl << "----------------------------------------------------"
		<< std::endl;
}

/* ******************************* DESTRUCTOR ******************************* */
ClapTrap::~ClapTrap(void)
{
	std::cout << "[Destructor]: " << this->_name << " has been destroyed."
		<< std::endl << "----------------------------------------------------"
		<< std::endl;
}
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
ClapTrap& ClapTrap::operator=(ClapTrap clapTrap)
{
	swap(*this, clapTrap);
	std::cout << "[Copy assignment operator]: " << this->_name
		<< " has been copied." << std::endl << "\t- " << this->_hitPts
		<< " Hit Points," << std::endl << "\t- " << this->_energyPts 
		<< " Energy Points," << std::endl << "\t- " << this->_damagePts
		<< " Damage Points." << std::endl
		<< "----------------------------------------------------" << std::endl;
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
	if (!this->_energyPts)
	{
		std::cout << "[Attack]: " << this->_name << " has no more energy"
			<< " points left. Attack aborted!!" << std::endl
			<< "----------------------------------------------------"
			<< std::endl;
		return ;
	}
	std::cout << "[Attack]: " << this->_name << " has been destroyed."
		<< std::endl << "----------------------------------------------------"
		<< std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{

}

void	ClapTrap::beRepaired(unsigned int amount)
{
	
}
