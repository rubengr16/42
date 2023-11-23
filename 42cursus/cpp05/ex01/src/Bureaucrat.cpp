/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:33:32 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/23 19:16:46 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* ****************************** CONSTRUCTORS ****************************** */
Bureaucrat::Bureaucrat(void):
	_name("DefaultBureaucrat"),
	_grade(MIN_GRADE)
{
	std::cout << "[Default Constructor] Bureaucrat: named as " << this->_name
		<< " and grade " << this->_grade << " has been created" << std::endl
		<< "----------------------------------------------------" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade):
	_name(name)
{
	if (grade < MAX_GRADE)
		throw (GradeTooHighException());
	if (grade > MIN_GRADE)
		throw (GradeTooLowException());
	this->_grade = grade;
	std::cout << "[Constructor] Bureaucrat: named as " << this->_name
		<< " and grade " << this->_grade << " has been created" << std::endl
		<< "----------------------------------------------------" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat):
	_name(bureaucrat.getName()),
	_grade(bureaucrat.getGrade())
{
	std::cout << "[Copy Constructor] Bureaucrat: named as " << this->_name
		<< " and grade " << this->_grade << " has been created" << std::endl
		<< "----------------------------------------------------" << std::endl;
}

/* ******************************* DESTRUCTOR ******************************* */
Bureaucrat::~Bureaucrat(void)
{
	std::cout << "[Destructor] Bureaucrat: named as " << this->_name
		<< " and grade " << this->_grade << " is being destroyed" << std::endl
		<< "----------------------------------------------------" << std::endl;
}

/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& bureaucrat)
{
	if (this == &bureaucrat)
		return (*this);
	this->_grade = bureaucrat.getGrade();
	std::cout << "[Copy Assignment Operator] Bureaucrat: named as "
		<< this->_name << " and grade " << this->_grade << " has been copy "
		<< "assigned" << std::endl
		<< "----------------------------------------------------" << std::endl;
	return (*this);
}

/* **************************** MEMBER FUNCTIONS **************************** */
const std::string&	Bureaucrat::getName(void) const
{
	return (this->_name);
}

unsigned int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::setGrade(unsigned int grade)
{
	if (grade < MAX_GRADE)
		throw (GradeTooHighException());
	if (grade > MIN_GRADE)
		throw (GradeTooLowException());
	this->_grade = grade;
}

void	Bureaucrat::incrementGrade(void)
{
	if (this->_grade <= MAX_GRADE)
		throw (GradeTooHighException());
	this->_grade--;
}

void	Bureaucrat::decrementGrade(void)
{
	if (this->_grade >= MIN_GRADE)
		throw (GradeTooLowException());
	this->_grade++;
}

void	Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch (const Form::GradeTooLowException& e)
	{
		std::cout << this->_name << " could'n sign " << form.getName()
			<< " because " << e.what() << std::endl;
	}
}


/* ************************* INPUT OPERATOR OVERLOAD ************************ */
std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade "
		<< bureaucrat.getGrade() << ".";
	return (os);
}

/* ******************************* EXCEPTIONS ******************************* */
const char*	Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("[What] Bureaucrat: Error! Grade too high");
}

const char*	Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("[What] Bureaucrat: Error! Grade too low");
}
