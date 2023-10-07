/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:21:06 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/07 16:46:35 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): nb(0)
{
	std::cout << "Default constructor called"
		<< std::endl;
}

Fixed::Fixed(const int nb): nb(nb << this->point)
{
	std::cout << "Int constructor called"
		<< std::endl;
	
}

Fixed::Fixed(const float nb): nb(roundf(nb * (1 << this->point)))
{
	std::cout << "Float constructor called"
		<< std::endl;
	
}

Fixed::Fixed(const Fixed& fixed): nb(fixed.nb)
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
	this->nb = fixed.nb;
	std::cout << "Copy assignment operator called"
		<< std::endl;
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called"
		<< std::endl;
	return (this->nb);
}

std::ostream&	operator<<(std::ostream &os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}

void	Fixed::setRawBits(int const raw)
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

