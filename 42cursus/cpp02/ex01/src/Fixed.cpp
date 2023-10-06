/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:21:06 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/07 01:03:08 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): nb(0)
{
	std::cout << "Default constructor called"
		<< std::endl;
}

Fixed::Fixed(int const nb): nb(nb << this->point)
{
	std::cout << "Int constructor called"
		<< std::endl;
	
}

Fixed::Fixed(float const nb): nb(roundf(nb << this->point))
{
	std::cout << "Float constructor called"
		<< std::endl;
	
}

Fixed::Fixed(Fixed &fixed): nb(fixed.nb)
{
	std::cout << "Copy constructor called"
		<< std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called"
		<< std::endl;
}

Fixed&	Fixed::operator=(const Fixed& fixed)
{
	std::cout << "Copy assignment operator called"
		<< std::endl;
	this->nb = fixed.nb;
	return (*this);
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called"
		<< std::endl;
	return (this->nb);
}

std::ostream&	operator<<(std::ostream &os, const Fixed& fixed)
{
	os << ".";
	return os;
}

void	Fixed::setRawBits( int const raw )
{
	this->nb = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->nb / (1 << this->point));
}

int	Fixed::toInt(void) const
{
	return (this->nb >> this->point);
}

