/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 22:57:24 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/15 00:35:34 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"

/* ****************************** CONSTRUCTORS ****************************** */
Animal::Animal(void):
	_type("Animal")
{
	std::cout << "[Default Constructor] Animal: object of type " << this->_type
		<< " has been created." << std::endl
		<< "----------------------------------------------------" << std::endl;
}

Animal::Animal(const Animal& animal):
	_type(animal.getType())
{
	std::cout << "[Copy Constructor] Animal: object of type " << this->_type
		<< " has been created." << std::endl
		<< "----------------------------------------------------" << std::endl;
}
/* ******************************* DESTRUCTOR ******************************* */
Animal::~Animal(void)
{
	std::cout << "[Destructor]: Animal: " << this->_type
		<< "'s type object has been destroyed." << std::endl
		<< "----------------------------------------------------" << std::endl;
}

/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
Animal&	Animal::operator=(const Animal& animal)
{
	if (this == &animal)
		return (*this);
	this->_type = animal._type;
	std::cout << "[Copy Assignment Operator] Animal: object of type "
		<< this->_type << " has been copy assigned." << std::endl
		<< "----------------------------------------------------" << std::endl;
	return (*this);
}

/* **************************** MEMBER FUNCTIONS **************************** */
std::string	Animal::getType(void) const
{
	return (this->_type);
}

void	Animal::makeSound(void) const
{
	std::cout << "[Make Sound] Animal: object of type "
		<< this->_type << " is making some animal's noise." << std::endl
		<< "----------------------------------------------------" << std::endl;
}

