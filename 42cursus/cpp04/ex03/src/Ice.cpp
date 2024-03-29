/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 00:12:29 by rgallego          #+#    #+#             */
/*   Updated: 2023/12/02 14:00:03 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

/* ****************************** CONSTRUCTORS ****************************** */
Ice::Ice(void):
	AMateria("ice")
{
	std::cout << "[Default Constructor] Ice: object of type " << this->_type
		<< " has been created" << std::endl
		<< "----------------------------------------------------" << std::endl;
}

Ice::Ice(const std::string& type):
	AMateria(type)
{
	std::cout << "[Constructor] Ice: object of type " << this->_type
		<< " has been created" << std::endl
		<< "----------------------------------------------------" << std::endl;
}

Ice::Ice(const Ice& ice):
	AMateria(ice.getType())
{
	std::cout << "[Copy Constructor] Ice: object of type " << this->_type
		<< " has been copy created" << std::endl
		<< "----------------------------------------------------" << std::endl;
}

/* ******************************* DESTRUCTOR ******************************* */
Ice::~Ice(void)
{
	std::cout << "[Destructor]: Ice: " << this->_type
		<< "'s type object has been destroyed" << std::endl
		<< "----------------------------------------------------" << std::endl;
}

/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
Ice&	Ice::operator=(const Ice& ice)
{
	if (this == &ice)
		return (*this);
	this->_type = ice.getType();
	std::cout << "[Copy Assignment Operator] Ice: object of type " << this->_type
		<< " has been copy assigned" << std::endl
		<< "----------------------------------------------------" << std::endl;
	return (*this);
}

/* **************************** MEMBER FUNCTIONS **************************** */
AMateria*	Ice::clone(void) const
{
	std::cout << "[Clone]: Ice: " << this->_type
		<< "'s type object is being cloned" << std::endl
		<< "----------------------------------------------------" << std::endl;
	return (new Ice(this->_type));
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
