/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IntegerList.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:55:33 by rgallego          #+#    #+#             */
/*   Updated: 2024/01/16 10:58:59 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IntegerVector.hpp"
#include <iostream>
/* ****************************** CONSTRUCTORS ****************************** */
IntegerVector::IntegerVector(void):
	std::vector<unsigned int>(),
	AContainer()
{
}

IntegerVector::IntegerVector(size_t n):
	std::vector<unsigned int>(n),
	AContainer()
{
}

IntegerVector::IntegerVector(char** values):
	std::vector<unsigned int>(),
	AContainer()
{
	size_t	i = 0;

	while (values[i] && i < std::numeric_limits<size_t>::max())
	{
		push_back(this->get_number(values[i]));
		i++;
	}
	if (i == std::numeric_limits<size_t>::max())
		throw (TooMuchNumbersException());
}

IntegerVector::IntegerVector(const IntegerVector& rhs):
	std::vector<unsigned int>(rhs),
	AContainer()
{
}

/* ******************************* DESTRUCTOR ******************************* */
IntegerVector::~IntegerVector(void)
{
}

/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
IntegerVector&	IntegerVector::operator=(const IntegerVector& rhs)
{
	std::vector<unsigned int>::operator=(rhs);
	return (*this);
}

unsigned int&	IntegerVector::get(size_t n)
{
	return (this->at(n));
}
