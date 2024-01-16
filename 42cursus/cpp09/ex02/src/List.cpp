/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:55:33 by rgallego          #+#    #+#             */
/*   Updated: 2024/01/16 10:58:59 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "List.hpp"

/* ****************************** CONSTRUCTORS ****************************** */
List::List(void):
	std::list<unsigned int>()
{
}

List::List(const List& rhs):
	std::list<unsigned int>(rhs)
{
}

/* ******************************* DESTRUCTOR ******************************* */
List::~List(void)
{
}

/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
List&	List::operator=(const List& rhs)
{
	std::list<unsigned int>::operator=(rhs);
	return (*this);
}

unsigned int&	List::at(size_t n)
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
