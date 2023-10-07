/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 00:40:08 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/08 01:07:33 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/* ****************************** CONSTRUCTORS ****************************** */
Point::Point(void)
{
}

Point::Point(const float x, const float y): _x(x), _y(y)
{
}


Point::Point(const Point& point)
{
	this->_x = point.getX();
	this->_y = point.getY();
}

/* ******************************* DESTRUCTOR ******************************* */
Point::~Point(void)
{
}

/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
Point&	Point::operator=(const Point& point)
{
	this->_x = point.getX();
	this->_y = point.getY();
}

/* **************************** MEMBER FUNCTIONS **************************** */
const Fixed&	Point::getX(void) const
{
	return (this->_x);
}

void	Point::setX(Fixed& x)
{
	this->_x = x;
}

const Fixed&	Point::getY(void) const
{
	return (this->_y);
}

void	Point::setY(Fixed& y)
{
	this->_y = y;
}
