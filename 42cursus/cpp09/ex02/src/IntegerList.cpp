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
	std::list<unsigned int>()
{
}

IntegerList::IntegerList(const IntegerList& rhs):
	std::list<unsigned int>(rhs)
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

unsigned int&	IntegerList::at(size_t n)
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
