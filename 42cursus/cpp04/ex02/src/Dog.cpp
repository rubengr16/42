/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 22:57:24 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/17 15:30:28 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dog.hpp"

/* ****************************** CONSTRUCTORS ****************************** */
Dog::Dog(void):
	AAnimal(),
	_brain(new Brain)
{
	this->_type = "Dog";
	std::cout << "[Default Constructor] Dog: object of type " << this->_type
		<< " has been created." << std::endl
		<< "----------------------------------------------------" << std::endl;
}

Dog::Dog(const Brain& brain):
	AAnimal(),
	_brain(new Brain(brain))
{
	this->_type = "Dog";
	std::cout << "[Constructor] Cat: object of type " << this->_type
		<< " has been created." << std::endl
		<< "----------------------------------------------------" << std::endl;
}

Dog::Dog(const Dog& dog):
	AAnimal(dog),
	_brain(new Brain(dog.getBrain()->getIdeas(), dog.getBrain()->getLength()))
{
	this->_type = dog._type;
	std::cout << "[Copy Constructor] Dog: object of type " << this->_type
		<< " has been created." << std::endl
		<< "----------------------------------------------------" << std::endl;
}
/* ******************************* DESTRUCTOR ******************************* */
Dog::~Dog(void)
{
	delete this->_brain;
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
const Brain*	Dog::getBrain(void) const
{
	return (this->_brain);
}

void	Dog::makeSound(void) const
{
	std::cout << "[Make Sound] Dog: object of type "
		<< this->_type << " is barking: wofwofwof." << std::endl
		<< "----------------------------------------------------" << std::endl;
}
