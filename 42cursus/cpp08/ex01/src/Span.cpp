/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:16:15 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/28 12:48:46 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* ****************************** CONSTRUCTORS ****************************** */
Span::Span(void):
	_size(0)
{
	std::cout << "[Default Constructor] Span: with size " << this->_size
		<< " has been created" << std::endl;
}

Span::Span(unsigned int size):
	_size(size)
{
	std::cout << "[Constructor] Span: with size " << this->_size
		<< " has been created" << std::endl;
}

Span::Span(const Span& span):
	_size(span.getSize()),
	_vector(span.getVector())
{
	std::cout << "[Constructor] Span: with size " << this->_size
		<< " has been created" << std::endl;
}

/* ******************************* DESTRUCTOR ******************************* */
Span::~Span(void)
{
	std::cout << "[Constructor] Span: with size " << this->_size
		<< " is being destructed" << std::endl;
}

/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
Span&	Span::operator=(const Span& span)
{
	std::cout << "[Copy Assignment Operator] Span: with size " << this->_size
		<< " is being copy assigned" << std::endl;
	this->_size = span.getSize();
	this->_vector = span.getVector();
}

/* **************************** MEMBER FUNCTIONS **************************** */
int	Span::longestSpan(void)
{
	if (this->_vector.size() < 2)
		throw (NoEnoughElemsException());
	return (*std::max_element(this->_vector.begin(), this->_vector.end())
		- *std::min_element(this->_vector.begin(), this->_vector.end()));
}

/**
 * it1: iterates over the vector
 * it2: iterates from it1 elem until the end to calculate each span
*/
int	Span::shortestSpan(void)
{
	std::vector<int>::iterator	it1;
	std::vector<int>::iterator	it2;
	int							minSpan = std::numeric_limits<int>::max();

	if (this->_vector.size() < 2)
		throw (NoEnoughElemsException());
	for (it1 = this->_vector.begin(); it1 != this->_vector.end(); ++it1)
		for (it2 = it1 + 1; it2 != this->_vector.end(); ++it2)
			if (abs(*it1 - *it2) < minSpan)
				minSpan = abs(*it1 - *it2);
	return (minSpan);
}

void	Span::addNumber(int nb)
{
	if (this->_vector.size() >= this->_size)
		throw (VectorIsFullException());
	this->_vector.push_back(nb);
}

unsigned int	Span::getSize(void)const 
{
	return (this->_size);
}

const std::vector<int>&	Span::getVector(void) const
{
	return (this->_vector);
}

/* ******************************* EXCEPTIONS ******************************* */
const char*	Span::VectorIsFullException::what(void) const throw()
{
	return ("[What] Span: Error! Vector is full");
}

const char*	Span::NoEnoughElemsException::what(void) const throw()
{
	return ("[What] Span: Error! Vector does not have enough elems for span");
}

