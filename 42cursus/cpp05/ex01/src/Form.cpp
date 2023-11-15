/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 00:12:07 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/15 15:10:54 by rgallego         ###   ########.fr       */
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
		<< ", " << this->_signed << " has been created" << std::endl
		<< "----------------------------------------------------" << std::endl;
}

Form::Form(std::string name, unsigned int gradeSign,
	unsigned int gradeExecute):
	_name(name),
	_signed(false),
	_gradeSign(gradeSign),
	_gradeExecute(gradeExecute)
{
	
}

Form::Form(const Form& form):
	_name(form.getName()),
	_signed(form.getSigned()),
	_gradeSign(form.getGradeSign()),
	_gradeExecute(form.getGradeExecute())
{

}

/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
Form&	Form::operator=(const Form& form)
{
	if (this == &form)
		return (*this);
	this->_signed = form.getSigned();
	return (*this);
}

/* ******************************* DESTRUCTOR ******************************* */
Form::~Form(void)
{

}

/* **************************** MEMBER FUNCTIONS **************************** */
const std::string&	Form::getName(void) const
{
	return (this->_name);
}

bool	Form::getSigned(void) const
{
	return (this->_signed);
}

const unsigned int	Form::getGradeSign(void) const
{
	return (this->_gradeSign);
}

const unsigned int	Form::getGradeExecute(void) const
{
	return (this->_gradeExecute);
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
