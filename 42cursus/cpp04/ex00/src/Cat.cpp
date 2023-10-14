/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 22:57:24 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/15 00:35:45 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cat.hpp"

/* ****************************** CONSTRUCTORS ****************************** */
Cat::Cat(void):
	Animal()
{
	this->_type = "Cat";
	std::cout << "[Default Constructor] Cat: object of type " << this->_type
		<< " has been created." << std::endl
		<< "----------------------------------------------------" << std::endl;
}

Cat::Cat(const Cat& cat):
	Animal(cat)
{
	this->_type = cat._type;
	std::cout << "[Copy Constructor] Cat: object of type " << this->_type
		<< " has been created." << std::endl
		<< "----------------------------------------------------" << std::endl;
}
/* ******************************* DESTRUCTOR ******************************* */
Cat::~Cat(void)
{
	std::cout << "[Destructor]: Cat: " << this->_type
		<< "'s type object has been destroyed." << std::endl
		<< "----------------------------------------------------" << std::endl;
}

/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
Cat&	Cat::operator=(const Cat& cat)
{
	if (this == &cat)
		return (*this);
	this->_type = cat._type;
	std::cout << "[Copy Assignment Operator] Cat: object of type "
		<< this->_type << " has been copy assigned." << std::endl
		<< "----------------------------------------------------" << std::endl;
	return (*this);
}

/* **************************** MEMBER FUNCTIONS **************************** */
void	Cat::makeSound(void) const
{
	std::cout << "[Make Sound] Cat: object of type "
		<< this->_type << " is meowing: meowmeowmeow." << std::endl
		<< "----------------------------------------------------" << std::endl;
}
