/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:16:15 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/23 22:30:09 by rgallego         ###   ########.fr       */
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

/* ******************************* EXCEPTIONS ******************************* */
const char*	Span::ElemNotFoundException::what(void) const throw()
{
	return ("[What] EasyFind: Error! skjdhgdfkjlhgkdfjhgkjdfhgj");
}

