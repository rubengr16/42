/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:21:06 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/14 22:30:10 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* ****************************** CONSTRUCTORS ****************************** */
Fixed::Fixed(void): _nb(0)
{
	std::cout << "Default constructor called"
		<< std::endl;
}

Fixed::Fixed(const Fixed &fixed): _nb(fixed.getRawBits())
{
	std::cout << "Copy constructor called"
		<< std::endl;
}

/* ******************************* DESTRUCTOR ******************************* */
Fixed::~Fixed(void)
{
	std::cout << "Destructor called"
		<< std::endl;
}

/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
Fixed& Fixed::operator=(const Fixed& fixed)
{
	std::cout << "Copy assignment operator called"
		<< std::endl;
	this->_nb = fixed.getRawBits();
	return (*this);
}

/* **************************** MEMBER FUNCTIONS **************************** */
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called"
		<< std::endl;
	return (this->_nb);
}

void Fixed::setRawBits(const int raw)
{
	this->_nb = raw;
}
