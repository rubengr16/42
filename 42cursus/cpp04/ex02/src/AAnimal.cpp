/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 22:57:24 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/14 00:10:30 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AAnimal.hpp"

/* ****************************** CONSTRUCTORS ****************************** */
AAnimal::AAnimal(void):
	_type("AAnimal")
{
	std::cout << "[Default Constructor] AAnimal: object of type " << this->_type
		<< " has been created." << std::endl
		<< "----------------------------------------------------" << std::endl;
}

AAnimal::AAnimal(const AAnimal& animal):
	_type(animal.getType())
{
	std::cout << "[Copy Constructor] AAnimal: object of type " << this->_type
		<< " has been created." << std::endl
		<< "----------------------------------------------------" << std::endl;
}
/* ******************************* DESTRUCTOR ******************************* */
AAnimal::~AAnimal(void)
{
	std::cout << "[Destructor]: AAnimal: " << this->_type
		<< "'s type object has been destroyed." << std::endl
		<< "----------------------------------------------------" << std::endl;
}

/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
AAnimal&	AAnimal::operator=(const AAnimal& animal)
{
	if (this == &animal)
		return (*this);
	this->_type = animal._type;
	std::cout << "[Copy Assignment Operator] AAnimal: object of type "
		<< this->_type << " has been copy assigned." << std::endl
		<< "----------------------------------------------------" << std::endl;
	return (*this);
}

/* **************************** MEMBER FUNCTIONS **************************** */
const std::string&	AAnimal::getType(void) const
{
	return (this->_type);
}
