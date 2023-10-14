/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 22:57:24 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/12 23:49:09 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "WrongAnimal.hpp"

/* ****************************** CONSTRUCTORS ****************************** */
WrongAnimal::WrongAnimal(void)
{
	this->_type = "WrongAnimal";
	std::cout << "[Default Constructor] WrongAnimal: object of type " << this->_type
		<< " has been created." << std::endl
		<< "----------------------------------------------------" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& wrongAnimal)
{
	this->_type = wrongAnimal._type;
	std::cout << "[Copy Constructor] WrongAnimal: object of type " << this->_type
		<< " has been created." << std::endl
		<< "----------------------------------------------------" << std::endl;
}
/* ******************************* DESTRUCTOR ******************************* */
WrongAnimal::~WrongAnimal(void)
{
	std::cout << "[Destructor]: WrongAnimal: " << this->_type
		<< "'s type object has been destroyed." << std::endl
		<< "----------------------------------------------------" << std::endl;
}

/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& wrongAnimal)
{
	this->_type = wrongAnimal._type;
	std::cout << "[Copy Assignment Operator] WrongAnimal: object of type "
		<< this->_type << " has been copy assigned." << std::endl
		<< "----------------------------------------------------" << std::endl;
	return (*this);
}

/* **************************** MEMBER FUNCTIONS **************************** */
std::string	WrongAnimal::getType(void) const
{
	return (this->_type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "[Make Sound] WrongAnimal: object of type "
		<< this->_type << " is making some wrongAnimal's noise." << std::endl
		<< "----------------------------------------------------" << std::endl;
}

