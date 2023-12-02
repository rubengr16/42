/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 00:12:29 by rgallego          #+#    #+#             */
/*   Updated: 2023/12/02 13:59:46 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

/* ****************************** CONSTRUCTORS ****************************** */
Cure::Cure(void):
	AMateria("cure")
{
	std::cout << "[Default Constructor] Cure: object of type " << this->_type
		<< " has been created" << std::endl
		<< "----------------------------------------------------" << std::endl;
}

Cure::Cure(const std::string& type):
	AMateria(type)
{
	std::cout << "[Constructor] Cure: object of type " << this->_type
		<< " has been created" << std::endl
		<< "----------------------------------------------------" << std::endl;
}

Cure::Cure(const Cure& cure):
	AMateria(cure.getType())
{
	std::cout << "[Copy Constructor] Cure: object of type " << this->_type
		<< " has been copy created" << std::endl
		<< "----------------------------------------------------" << std::endl;
}

/* ******************************* DESTRUCTOR ******************************* */
Cure::~Cure(void)
{
	std::cout << "[Destructor]: Cure: " << this->_type
		<< "'s type object has been destroyed" << std::endl
		<< "----------------------------------------------------" << std::endl;
}


/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
Cure&	Cure::operator=(const Cure& cure)
{
	if (this == &cure)
		return (*this);
	this->_type = cure.getType();
	std::cout << "[Copy Assignment Operator] Cure: object of type " << this->_type
		<< " has been copy assigned" << std::endl
		<< "----------------------------------------------------" << std::endl;
	return (*this);
}

/* **************************** MEMBER FUNCTIONS **************************** */
AMateria*	Cure::clone(void) const
{
	std::cout << "[Clone]: Cure: " << this->_type
		<< "'s type object is being cloned" << std::endl
		<< "----------------------------------------------------" << std::endl;
	return (new Cure(this->_type));
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
