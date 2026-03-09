/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 00:12:07 by rgallego          #+#    #+#             */
/*   Updated: 2024/07/31 12:18:33 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/* ****************************** CONSTRUCTORS ****************************** */
AForm::AForm(void):
	_name("DefaultAForm"),
	_signed(false),
	_gradeSign(MIN_GRADE),
	_gradeExecute(MIN_GRADE),
	_target("AFormTarget")
{
	std::cout << "[Default Constructor] AForm: named as " << this->_name
		<< " has been created. It is " << (this->_signed ? "" : "not ")
		<< "signed and requires " << this->_gradeSign << " to be signed and "
		<< this->_gradeExecute << " to be executed, which targets "
		<< this->_target << std::endl
		<< "----------------------------------------------------" << std::endl;
}

AForm::AForm(const std::string& name, unsigned int gradeSign,
	unsigned int gradeExecute, const std::string& target):
	_name(name),
	_signed(false),
	_gradeSign(checkGrade(gradeSign)),
	_gradeExecute(checkGrade(gradeExecute)),
	_target(target)
{
	std::cout << "[Constructor] AForm: named as " << this->_name
		<< " has been created. It is " << (this->_signed ? "" : "not ")
		<< "signed and requires " << this->_gradeSign << " to be signed and "
		<< this->_gradeExecute << " to be executed, which targets "
		<< this->_target << std::endl
		<< "----------------------------------------------------" << std::endl;
}

AForm::AForm(const AForm& form):
	_name(form.getName()),
	_signed(form.getSigned()),
	_gradeSign(form.getGradeSign()),
	_gradeExecute(form.getGradeExecute()),
	_target(this->getTarget())
{
	std::cout << "[Copy Constructor] AForm: named as " << this->_name
		<< " has been created. It is " << (this->_signed ? "" : "not ")
		<< "signed and requires " << this->_gradeSign << " to be signed and "
		<< this->_gradeExecute << " to be executed, which targets "
		<< this->_target << std::endl
		<< "----------------------------------------------------" << std::endl;
}

/* ******************************* DESTRUCTOR ******************************* */
AForm::~AForm(void)
{
	std::cout << "[Copy Assignment Operator] AForm: named as " << this->_name
		<< " is being deleted" << std::endl
		<< "----------------------------------------------------" << std::endl;
}

/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
AForm&	AForm::operator=(const AForm& form)
{
	if (this == &form)
		return (*this);
	this->_signed = form.getSigned();
	std::cout << "[Copy Assignment Operator] AForm: named as " << this->_name
		<< " has been copy assigned. It is " << (this->_signed ? "" : "not ")
		<< "signed and requires " << this->_gradeSign << " to be signed and "
		<< this->_gradeExecute << " to be executed. And targets "
		<< this->_target << std::endl
		<< "----------------------------------------------------" << std::endl;
	return (*this);
}

/* **************************** MEMBER FUNCTIONS **************************** */
unsigned int	AForm::checkGrade(unsigned int grade) const
{
	if (grade < MAX_GRADE)
		throw (GradeTooHighException());
	if (grade > MIN_GRADE)
		throw (GradeTooLowException());
	return (grade);
}

void	AForm::checkSigned(void) const
{
	if (!this->_signed)
		throw (NotSignedException());
}

void	AForm::checkExecute(unsigned int grade) const
{
	if (grade > this->_gradeExecute)
		throw (GradeTooLowException());
}

const std::string&	AForm::getName(void) const
{
	return (this->_name);
}

bool	AForm::getSigned(void) const
{
	return (this->_signed);
}

unsigned int	AForm::getGradeSign(void) const
{
	return (this->_gradeSign);
}

unsigned int	AForm::getGradeExecute(void) const
{
	return (this->_gradeExecute);
}

const std::string&	AForm::getTarget(void) const
{
	return (this->_target);
}

void	AForm::setTarget(const std::string& target)
{
	this->_target = target;
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeSign)
		throw (GradeTooLowException());
	this->_signed = true;
}

/* ************************* INPUT OPERATOR OVERLOAD ************************ */
std::ostream&	operator<<(std::ostream& os, const AForm& form)
{
	os << form.getName() << " is " << (form.getSigned() ? "" : "not ")
		<< "signed and requires " << form.getGradeSign()
		<< " to be signed and " << form.getGradeExecute() << " to be executed."
		<< std::endl;
	return os;
}

/* ******************************* EXCEPTIONS ******************************* */
const char*	AForm::GradeTooHighException::what(void) const throw()
{
	return ("[What] AForm: Error! Grade too high");
}

const char*	AForm::GradeTooLowException::what(void) const throw()
{
	return ("[What] AForm: Error! Grade too low");
}

const char*	AForm::NotSignedException::what(void) const throw()
{
	return ("[What] AForm: Error! Form is not signed yet");
}

