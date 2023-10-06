/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:21:06 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/06 15:55:36 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): nb(0)
{
}

Fixed::Fixed(Fixed &fixed): nb(fixed.nb)
{
}

Fixed::~Fixed(void)
{
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
	this->nb = fixed.nb;
}

int Fixed::getRawBits( void ) const
{
	return (this->nb);
}

void Fixed::setRawBits( int const raw )
{
	this->nb = raw;
}
