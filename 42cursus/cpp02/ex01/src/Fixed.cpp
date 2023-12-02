/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:21:06 by rgallego          #+#    #+#             */
/*   Updated: 2023/12/02 13:41:35 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* ****************************** CONSTRUCTORS ****************************** */
Fixed::Fixed(void): _nb(0)
{
	std::cout << "Default constructor called"
		<< std::endl;
}

Fixed::Fixed(const int nb): _nb(nb << this->_point)
{
	std::cout << "Int constructor called"
		<< std::endl;
}

Fixed::Fixed(const float nb): _nb(roundf(nb * (1 << this->_point)))
{
	std::cout << "Float constructor called"
		<< std::endl;
}

Fixed::Fixed(const Fixed& fixed): _nb(fixed.getRawBits())
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

/* ******************************* DESTRUCTOR ******************************* */
Fixed&	Fixed::operator=(const Fixed& fixed)
{
	if (this == &fixed)
		return (*this);
	this->_nb = fixed.getRawBits();
	std::cout << "Copy assignment operator called"
		<< std::endl;
	return (*this);
}

/* **************************** MEMBER FUNCTIONS **************************** */
int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called"
		<< std::endl;
	return (this->_nb);
}

void	Fixed::setRawBits(const int raw)
{
	this->_nb = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_nb / (1 << this->_point));
}

int	Fixed::toInt(void) const
{
	return (this->_nb >> this->_point);
}

/* ************************ INPUT OPERATOR OVERLOAD ************************ */
std::ostream&	operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}
