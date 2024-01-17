/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AContainer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:50:41 by rgallego          #+#    #+#             */
/*   Updated: 2024/01/17 14:43:15 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AContainer.hpp"

/* ****************************** CONSTRUCTORS ****************************** */
AContainer::AContainer(void)
{
}

AContainer::AContainer(char** values)
{
	std::stringstream	stream;
	long long int		value;
	unsigned int		i = 0;

	while (values[i])
	{
		stream << values[i];
		stream >> value;
		if (!stream.eof()
			|| (value != -std::numeric_limits<unsigned int>::infinity()
			&& value != std::numeric_limits<unsigned int>::infinity()
			&& (value < -std::numeric_limits<unsigned int>::max()
			|| std::numeric_limits<unsigned int>::max() < value 
			|| (errno == ERANGE && (value == -HUGE_VAL)))))
			throw (AContainer::OutOfRangeNumberException());
		AContainer::push_back(value);
		i++;
	}
}

AContainer::AContainer(const AContainer& rhs)
{
}

/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
AContainer&	AContainer::operator=(const AContainer& rhs)
{
	return (*this);
}

/* ******************************* DESTRUCTOR ******************************* */
AContainer::~AContainer(void)
{
}

/* ******************************* EXCEPTIONS ******************************* */
const char*	AContainer::OutOfRangeNumberException::what(void) const throw()
{
	return ("Error: the given number is not a positive integer.");
}
