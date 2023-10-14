/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 22:57:24 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/13 00:22:37 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "WrongCat.hpp"

/* ****************************** CONSTRUCTORS ****************************** */
WrongCat::WrongCat(void):
	WrongAnimal()
{
	this->_type = "WrongCat";
	std::cout << "[Default Constructor] WrongCat: object of type " << this->_type
		<< " has been created." << std::endl
		<< "----------------------------------------------------" << std::endl;
}

WrongCat::WrongCat(const WrongCat& wrongCat):
	WrongAnimal(wrongCat)
{
	this->_type = wrongCat._type;
	std::cout << "[Copy Constructor] WrongCat: object of type " << this->_type
		<< " has been created." << std::endl
		<< "----------------------------------------------------" << std::endl;
}
/* ******************************* DESTRUCTOR ******************************* */
WrongCat::~WrongCat(void)
{
	std::cout << "[Destructor]: WrongCat: " << this->_type
		<< "'s type object has been destroyed." << std::endl
		<< "----------------------------------------------------" << std::endl;
}

/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
WrongCat&	WrongCat::operator=(const WrongCat& wrongCat)
{
	if (this == &wrongCat)
		return (*this);
	this->_type = wrongCat._type;
	std::cout << "[Copy Assignment Operator] WrongCat: object of type "
		<< this->_type << " has been copy assigned." << std::endl
		<< "----------------------------------------------------" << std::endl;
	return (*this);
}

/* **************************** MEMBER FUNCTIONS **************************** */
void	WrongCat::makeSound(void) const
{
	std::cout << "[Make Sound] WrongCat: object of type "
		<< this->_type << " is meowing: meowmeowmeow." << std::endl
		<< "----------------------------------------------------" << std::endl;
}
