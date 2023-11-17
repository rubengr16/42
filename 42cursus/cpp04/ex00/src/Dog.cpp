/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 22:57:24 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/16 22:25:44 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dog.hpp"

/* ****************************** CONSTRUCTORS ****************************** */
Dog::Dog(void):
	Animal()
{
	this->_type = "Dog";
	std::cout << "[Default Constructor] Dog: object of type " << this->_type
		<< " has been created." << std::endl
		<< "----------------------------------------------------" << std::endl;
}

Dog::Dog(const Dog& dog):
	Animal(dog)
{
	this->_type = dog._type;
	std::cout << "[Constructor] Dog: object of type " << this->_type
		<< " has been created." << std::endl
		<< "----------------------------------------------------" << std::endl;
}
/* ******************************* DESTRUCTOR ******************************* */
Dog::~Dog(void)
{
	std::cout << "[Destructor]: Dog: " << this->_type
		<< "'s type object has been destroyed." << std::endl
		<< "----------------------------------------------------" << std::endl;
}

/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
Dog&	Dog::operator=(const Dog& dog)
{
	if (this == &dog)
		return (*this);
	this->_type = dog._type;
	std::cout << "[Copy Assignment Operator] Dog: object of type "
		<< this->_type << " has been copy assigned." << std::endl
		<< "----------------------------------------------------" << std::endl;
	return (*this);
}

/* **************************** MEMBER FUNCTIONS **************************** */
void	Dog::makeSound(void) const
{
	std::cout << "[Make Sound] Dog: object of type "
		<< this->_type << " is barking: wofwofwof." << std::endl
		<< "----------------------------------------------------" << std::endl;
}
