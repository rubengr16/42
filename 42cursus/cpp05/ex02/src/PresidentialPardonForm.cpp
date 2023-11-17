/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:20:30 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/17 15:42:23 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"

/* ****************************** CONSTRUCTORS ****************************** */
PresidentialPardonForm::PresidentialPardonForm(void):
	AForm("DefaultPresidentialPardonForm", SIGN_GRADE, EXECUTE_GRADE)
{
	std::cout << "[Default Constructor] PresidentialPardonForm: named as "
		<< this->_name << " has been created. It is "
		<< (this->_signed ? "" : "not ") << "signed and requires "
		<< this->_gradeSign << " to be signed and " << this->_gradeExecute
		<< " to be executed" << std::endl
		<< "----------------------------------------------------" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(
	const PresidentialPardonForm& pPForm):
	AForm(pPForm)
{
	std::cout << "[Copy Constructor] PresidentialPardonForm: named as "
		<< this->_name << " has been created. It is "
		<< (this->_signed ? "" : "not ") << "signed and requires "
		<< this->_gradeSign << " to be signed and " << this->_gradeExecute
		<< " to be executed" << std::endl
		<< "----------------------------------------------------" << std::endl;
}

/* ******************************* DESTRUCTOR ******************************* */
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "[Destructor] PresidentialPardonForm: named as "
		<< this->_name << " has been created. It is "
		<< (this->_signed ? "" : "not ") << "signed and requires "
		<< this->_gradeSign << " to be signed and " << this->_gradeExecute
		<< " is being destructed" << std::endl
		<< "----------------------------------------------------" << std::endl;
}

/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
PresidentialPardonForm&	PresidentialPardonForm::operator=(
	const PresidentialPardonForm& pPForm)
{
	std::cout << "[Copy Assignment Operator] PresidentialPardonForm: named as "
		<< this->_name << " has been created. It is "
		<< (this->_signed ? "" : "not ") << "signed and requires "
		<< this->_gradeSign << " to be signed and " << this->_gradeExecute
		<< " is being destructed" << std::endl
		<< "----------------------------------------------------" << std::endl;
}

/* **************************** MEMBER FUNCTIONS **************************** */
void	PresidentialPardonForm::execute(const Bureaucrat& bureaucrat)
{
	
}
