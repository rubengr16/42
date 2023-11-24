/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:16:15 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/24 23:33:19 by rgallego         ###   ########.fr       */
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

