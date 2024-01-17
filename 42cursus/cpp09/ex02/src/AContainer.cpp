/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AContainer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:50:41 by rgallego          #+#    #+#             */
/*   Updated: 2024/01/17 21:47:44 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AContainer.hpp"

/* ****************************** CONSTRUCTORS ****************************** */
AContainer::AContainer(void)
{
}

AContainer::AContainer(const AContainer& rhs)
{
	(void)rhs;
}

/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
AContainer&	AContainer::operator=(const AContainer& rhs)
{
	(void)rhs;
	return (*this);
}

/* ******************************* DESTRUCTOR ******************************* */
AContainer::~AContainer(void)
{
}

/* **************************** MEMBER FUNCTIONS **************************** */
unsigned int	AContainer::get_number(char *str)
{
	std::stringstream	stream (str);
	long long int		value;

	stream >> value;
	if (!stream.eof() || value < 0
		|| (value != -std::numeric_limits<unsigned int>::infinity()
		&& value != std::numeric_limits<unsigned int>::infinity()
		&& (value < -std::numeric_limits<unsigned int>::max()
		|| std::numeric_limits<unsigned int>::max() < value 
		|| (errno == ERANGE && value == -HUGE_VALL))))
		throw (AContainer::WrongNumberException());
	return (static_cast<unsigned int>(value));
}

/* ******************************* EXCEPTIONS ******************************* */
const char*	AContainer::WrongNumberException::what(void) const throw()
{
	return ("Error: the given number is not a positive integer.");
}

const char*	AContainer::TooMuchNumbersException::what(void) const throw()
{
	return ("Error: too much numbers were introduced.");
}
