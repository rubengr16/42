/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:16:15 by rgallego          #+#    #+#             */
/*   Updated: 2023/12/27 00:22:07 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* ****************************** CONSTRUCTORS ****************************** */
Span::Span(void):
	_maxSize(0)
{
	std::cout << "[Default Constructor] Span: with size " << this->_maxSize
		<< " has been created" << std::endl;
}

Span::Span(unsigned int size):
	_maxSize(size)
{
	std::cout << "[Constructor] Span: with size " << this->_maxSize
		<< " has been created" << std::endl;
}

Span::Span(const Span& span):
	_maxSize(span.getMaxSize()),
	_vector(span.getVector())
{
	std::cout << "[Constructor] Span: with size " << this->_maxSize
		<< " has been created" << std::endl;
}

/* ******************************* DESTRUCTOR ******************************* */
Span::~Span(void)
{
	std::cout << "[Constructor] Span: with size " << this->_maxSize
		<< " is being destructed" << std::endl;
}

/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
Span&	Span::operator=(const Span& span)
{
	std::cout << "[Copy Assignment Operator] Span: with size " << this->_maxSize
		<< " is being copy assigned" << std::endl;
	this->_maxSize = span.getMaxSize();
	this->_vector = span.getVector();
	return (*this);
}

/* **************************** MEMBER FUNCTIONS **************************** */
unsigned int	Span::getMaxSize(void)const 
{
	return (this->_maxSize);
}

const std::vector<int>&	Span::getVector(void) const
{
	return (this->_vector);
}

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
	if (this->_vector.size() >= this->_maxSize)
		throw (VectorIsFullException());
	this->_vector.push_back(nb);
}

void	Span::addNumber(int size, Generator generator)
{
	unsigned int				final_size;
	std::vector<int>::iterator	start_add;

	final_size = this->_vector.size() + size;
	if (this->_maxSize < final_size)
		throw (VectorIsFullException());
	this->_vector.reserve(final_size);
	start_add = this->_vector.end();
	this->_vector.resize(final_size);
	std::generate(start_add, this->_vector.end(), generator);
}

void	Span::print(void)
{
	std::vector<int>::iterator	it = this->_vector.begin();

	std::cout << "[ ";
	while (it != this->_vector.end())
	{
		std::cout << *it;
		++it;
		if (it != this->_vector.end())
			std::cout << ", ";
	}
	std::cout << "]" << std::endl;
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

