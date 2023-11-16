/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:20:30 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/16 14:41:47 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"

/* ****************************** CONSTRUCTORS ****************************** */
PresidentialPardonForm::PresidentialPardonForm(void):
	AForm("DefaultPresidentialPardonForm", SIGN_GRADE, EXECUTE_GRADE)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& pPForm)
{
	
}

/* ******************************* DESTRUCTOR ******************************* */
PresidentialPardonForm::~PresidentialPardonForm()
{

}

/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
PresidentialPardonForm&	PresidentialPardonForm::operator=(
	const PresidentialPardonForm& pPForm)
{

}

/* **************************** MEMBER FUNCTIONS **************************** */
void	PresidentialPardonForm::execute(const Bureaucrat& bureaucrat)
{
	
}
