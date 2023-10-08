/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:21:06 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/08 22:29:19 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* ****************************** CONSTRUCTORS ****************************** */
Fixed::Fixed(void): _nb(0)
{
}

Fixed::Fixed(const int nb): _nb(nb << this->_point)
{
}

Fixed::Fixed(const float nb): _nb(roundf(nb * (1 << this->_point)))
{
}

Fixed::Fixed(const Fixed& fixed): _nb(fixed.getRawBits())
{
}

/* ******************************* DESTRUCTOR ******************************* */
Fixed::~Fixed(void)
{
}

/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
Fixed&	Fixed::operator=(const Fixed& fixed)
{
	this->_nb = fixed.getRawBits();
	return (*this);
}

/* ********************** COMPARISON OPERATORS OVERLOAD ********************* */
std::ostream&	operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}

/* ********************** COMPARISON OPERATORS OVERLOAD ********************* */
bool	Fixed::operator<(const Fixed& fixed) const
{
	return (this->_nb < fixed.getRawBits());
}

bool	Fixed::operator>(const Fixed& fixed) const
{
	return (this->_nb > fixed.getRawBits());
}

bool	Fixed::operator<=(const Fixed& fixed) const
{
	return (this->_nb <= fixed.getRawBits());
}

bool	Fixed::operator>=(const Fixed& fixed) const
{
	return (this->_nb >= fixed.getRawBits());
}

bool	Fixed::operator==(const Fixed& fixed) const
{
	return (this->_nb == fixed.getRawBits());
}

bool	Fixed::operator!=(const Fixed& fixed) const
{
	return (this->_nb != fixed.getRawBits());
}

/* ********************** LOGICAL NOT OPERATOR OVERLOAD ********************* */
bool	Fixed::operator!(void)
{
	return (!this->getRawBits());
}
/* ********************* ARITHMETICS OPERATORS OVERLOAD ********************* */
Fixed	Fixed::operator+(const Fixed& fixed)
{
	return (Fixed(this->_nb + fixed.getRawBits()));
}

Fixed	Fixed::operator-(const Fixed& fixed)
{
	return (Fixed(this->_nb - fixed.getRawBits()));
}

Fixed	Fixed::operator*(const Fixed& fixed)
{
	return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed	Fixed::operator/(const Fixed& fixed)
{
	return (Fixed(this->toFloat() / fixed.toFloat()));
}

/* ******************** {IN/DE}CREMENT OPERATORS OVERLOAD ******************* */
Fixed	Fixed::operator++(int)
{
	Fixed	tmp = *this;
	this->setRawBits(this->_nb + 1);
	return (tmp);
}

Fixed&	Fixed::operator++(void)
{
	(this->_nb)++;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp = *this;
	this->setRawBits(this->_nb - 1);
	return (tmp);
}

Fixed&	Fixed::operator--(void)
{
	this->_nb--;
	return (*this);
}

/* **************************** MEMBER FUNCTIONS **************************** */
int	Fixed::getRawBits(void) const
{
	return (this->_nb);
}

void	Fixed::setRawBits(int const raw)
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

/* *********************** OVERLOADED MEMBER FUNCTIONS ********************** */
Fixed&	Fixed::min(Fixed& fixed1, Fixed& fixed2)
{
	if (fixed1.getRawBits() < fixed2.getRawBits())
		return (fixed1);
	return (fixed2);
}

const Fixed&	Fixed::min(const Fixed& fixed1, const Fixed& fixed2)
{
	if (fixed1.getRawBits() < fixed2.getRawBits())
		return (fixed1);
	return (fixed2);
}

Fixed&	Fixed::max(Fixed& fixed1, Fixed& fixed2)
{
	if (fixed2.getRawBits() > fixed1.getRawBits())
		return (fixed2);
	return (fixed1);
}

const Fixed&	Fixed::max(const Fixed& fixed1, const Fixed& fixed2)
{
	if (fixed2.getRawBits() > fixed1.getRawBits())
		return (fixed2);
	return (fixed1);
}
