/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 22:57:24 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/14 17:02:47 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cat.hpp"

/* ****************************** CONSTRUCTORS ****************************** */
Cat::Cat(void):
	Animal(),
	_brain(new Brain)
{
	this->_type = "Cat";
	std::cout << "[Default Constructor] Cat: object of type " << this->_type
		<< " has been created." << std::endl
		<< "----------------------------------------------------" << std::endl;
}

Cat::Cat(const Cat& cat):
	Animal(cat),
	_brain(new Brain(cat.getBrain()->getIdeas(), cat.getBrain()->getLength()))
{
	this->_type = cat._type;
	std::cout << "[Copy Constructor] Cat: object of type " << this->_type
		<< " has been created." << std::endl
		<< "----------------------------------------------------" << std::endl;
}
/* ******************************* DESTRUCTOR ******************************* */
Cat::~Cat(void)
{
	delete this->_brain;
	std::cout << "[Destructor]: Cat: " << this->_type
		<< "'s type object has been destroyed." << std::endl
		<< "----------------------------------------------------" << std::endl;
}

/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
Cat&	Cat::operator=(const Cat& cat)
{
	this->_type = cat._type;
	std::cout << "[Copy Assignment Operator] Cat: object of type "
		<< this->_type << " has been copy assigned." << std::endl
		<< "----------------------------------------------------" << std::endl;
	return (*this);
}

/* **************************** MEMBER FUNCTIONS **************************** */
const Brain*	Cat::getBrain(void) const
{
	return (this->_brain);
}

void	Cat::makeSound(void) const
{
	std::cout << "[Make Sound] Cat: object of type "
		<< this->_type << " is meowing: meowmeowmeow." << std::endl
		<< "----------------------------------------------------" << std::endl;
}
