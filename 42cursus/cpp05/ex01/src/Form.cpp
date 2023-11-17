/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 00:12:07 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/18 00:24:59 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* ****************************** CONSTRUCTORS ****************************** */
Form::Form(void):
	_name("DefaultForm"),
	_signed(false),
	_gradeSign(MIN_GRADE),
	_gradeExecute(MIN_GRADE)
{
	std::cout << "[Default Constructor] Form: named as " << this->_name
		<< " has been created. It is " << (this->_signed ? "" : "not ")
		<< "signed and requires " << this->_gradeSign << " to be signed and "
		<< this->_gradeExecute << " to be executed" << std::endl
		<< "----------------------------------------------------" << std::endl;
}

Form::Form(const std::string& name, unsigned int gradeSign,
	unsigned int gradeExecute):
	_name(name),
	_signed(false),
	_gradeSign(checkGrade(gradeSign)),
	_gradeExecute(checkGrade(gradeExecute))
{
	std::cout << "[Constructor] Form: named as " << this->_name
		<< " has been created. It is " << (this->_signed ? "" : "not ")
		<< "signed and requires " << this->_gradeSign << " to be signed and "
		<< this->_gradeExecute << " to be executed" << std::endl
		<< "----------------------------------------------------" << std::endl;
}

Form::Form(const Form& form):
	_name(form.getName()),
	_signed(form.getSigned()),
	_gradeSign(form.getGradeSign()),
	_gradeExecute(form.getGradeExecute())
{
	std::cout << "[Copy Constructor] Form: named as " << this->_name
		<< " has been created. It is " << (this->_signed ? "" : "not ")
		<< "signed and requires " << this->_gradeSign << " to be signed and "
		<< this->_gradeExecute << " to be executed" << std::endl
		<< "----------------------------------------------------" << std::endl;
}

/* ******************************* DESTRUCTOR ******************************* */
Form::~Form(void)
{
	std::cout << "[Copy Assignment Operator] Form: named as " << this->_name
		<< " is being deleted" << std::endl
		<< "----------------------------------------------------" << std::endl;
}

/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
Form&	Form::operator=(const Form& form)
{
	if (this == &form)
		return (*this);
	this->_signed = form.getSigned();
	std::cout << "[Copy Assignment Operator] Form: named as " << this->_name
		<< " has been copy assigned. It is " << (this->_signed ? "" : "not ")
		<< "signed and requires " << this->_gradeSign << " to be signed and "
		<< this->_gradeExecute << " to be executed" << std::endl
		<< "----------------------------------------------------" << std::endl;
	return (*this);
}

/* **************************** MEMBER FUNCTIONS **************************** */
unsigned int	Form::checkGrade(unsigned int grade) const
{
	if (grade < MAX_GRADE)
		throw GradeTooHighException();
	if (grade > MIN_GRADE)
		throw GradeTooLowException();
	return (grade);
}

const std::string&	Form::getName(void) const
{
	return (this->_name);
}

bool	Form::getSigned(void) const
{
	return (this->_signed);
}

unsigned int	Form::getGradeSign(void) const
{
	return (this->_gradeSign);
}

unsigned int	Form::getGradeExecute(void) const
{
	return (this->_gradeExecute);
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeSign)
		throw GradeTooLowException();
	this->_signed = true;
}

/* ************************* INPUT OPERATOR OVERLOAD ************************ */
std::ostream&	operator<<(std::ostream& os, const Form& form)
{
	os << form.getName() << " is " << (form.getSigned() ? "" : "not ")
		<< "signed and requires " << form.getGradeSign()
		<< " to be signed and " << form.getGradeExecute() << " to be executed."
		<< std::endl;
	return os;
}

/* ******************************* EXCEPTIONS ******************************* */
const char*	Form::GradeTooHighException::what(void) const throw()
{
	return ("[What] Form: Error! Grade too high");
}

const char*	Form::GradeTooLowException::what(void) const throw()
{
	return ("[What] Form: Error! Grade too low");
}
