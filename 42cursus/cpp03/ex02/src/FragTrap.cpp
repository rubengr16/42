/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 23:02:54 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/12 13:18:54 by rgallego         ###   ########.fr       */
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
FragTrap&	FragTrap::operator=(FragTrap fragTrap)
{
	return ((FragTrap&)ClapTrap::operator=(fragTrap));
}

/* **************************** MEMBER FUNCTIONS **************************** */
void	FragTrap::highFiveGuys(void)
{
	std::cout << "[High Five Guys]: FragTrap " << this->_name
		<< " high fives y'all! Nice to see you!!." << std::endl
		<< "----------------------------------------------------" << std::endl;
}
