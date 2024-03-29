/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 23:24:13 by rgallego          #+#    #+#             */
/*   Updated: 2023/12/02 13:59:00 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/* ****************************** CONSTRUCTORS ****************************** */
AMateria::AMateria(void)
{
	std::cout << "[Default Constructor] AMAteria: should never be created"
		<< std::endl << "----------------------------------------------------"
		<< std::endl;
}

AMateria::AMateria(const std::string& type):
	_type(type)
{
	std::cout << "[Constructor] AMateria: object of type " << this->_type
		<< " has been created" << std::endl
		<< "----------------------------------------------------" << std::endl;
}

AMateria::AMateria(const AMateria& materia)
{
	std::cout << "[Copy Constructor] AMAteria: should never be created"
		<< std::endl << "----------------------------------------------------"
		<< std::endl;
	this->_type = materia.getType();
}

/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
AMateria& AMateria::operator=(const AMateria& materia)
{
	if (this == &materia)
		return (*this);
	this->_type = materia.getType();
	std::cout << "[Copy Assignment Operator] AMAteria: should never be used"
		<< std::endl << "----------------------------------------------------"
		<< std::endl;
	return (*this);
}

/* ******************************* DESTRUCTOR ******************************* */
AMateria::~AMateria(void)
{
	std::cout << "[Destructor]: AMAteria: object has been destroyed"
		<< std::endl << "----------------------------------------------------"
		<< std::endl;
}

/* **************************** MEMBER FUNCTIONS **************************** */
const std::string& AMateria::getType(void) const
{
	return (this->_type);
}

void AMateria::setType(const std::string& type)
{
	this->_type = type;
}
