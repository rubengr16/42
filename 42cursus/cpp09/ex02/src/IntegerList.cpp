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

#include "IntegerList.hpp"
#include <iostream>
/* ****************************** CONSTRUCTORS ****************************** */
IntegerList::IntegerList(void):
	std::list<unsigned int>(),
	AContainer()
{
}

IntegerList::IntegerList(size_t n):
	std::list<unsigned int>(n),
	AContainer()
{
}

IntegerList::IntegerList(char** values):
	std::list<unsigned int>(),
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

IntegerList::IntegerList(const IntegerList& rhs):
	std::list<unsigned int>(rhs),
	AContainer()
{
}

/* ******************************* DESTRUCTOR ******************************* */
IntegerList::~IntegerList(void)
{
}

/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
IntegerList&	IntegerList::operator=(const IntegerList& rhs)
{
	std::list<unsigned int>::operator=(rhs);
	return (*this);
}

unsigned int&	IntegerList::get(size_t n)
{
	std::list<unsigned int>::iterator it;

	if (n < 0 || n >= this->size())
		throw (std::out_of_range::exception());
	it = this->begin();
	while (n)
	{
		it++;
		n--;
	}
	return (*it);
}
