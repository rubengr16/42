/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 22:57:24 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/14 23:13:06 by rgallego         ###   ########.fr       */
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
	this->_type = animal._type;
	std::cout << "[Copy Assignment Operator] AAnimal: object of type "
		<< this->_type << " has been copy assigned." << std::endl
		<< "----------------------------------------------------" << std::endl;
	return (*this);
}

/* **************************** MEMBER FUNCTIONS **************************** */
std::string	AAnimal::getType(void) const
{
	return (this->_type);
}
