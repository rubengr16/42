/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:33:32 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/13 23:30:04 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* ****************************** CONSTRUCTORS ****************************** */
Bureaucrat::Bureaucrat(void):
	_name("DefaultBureaucrat"),
	_grade(MIN_GRADE)
{
	std::cout << "[Default Constructor] Bureaucrat: named as" << this->_name
		<< " and grade " << this->_grade << " has been created" << std::endl
		<< "----------------------------------------------------" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade):
	_name(name),
	_grade(grade)
{
	std::cout << "[Constructor] Bureaucrat: named as" << this->_name
		<< " and grade " << this->_grade << " has been created" << std::endl
		<< "----------------------------------------------------" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat):
	_name(bureaucrat.getName()),
	_grade(bureaucrat.getGrade())
{
}

/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& bureaucrat)
{
	if (this == &bureaucrat)
		return (*this);
	this->_grade = bureaucrat.getGrade();
}

/* ******************************* DESTRUCTOR ******************************* */
Bureaucrat::~Bureaucrat(void)
{

}

/* **************************** MEMBER FUNCTIONS **************************** */
std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}
