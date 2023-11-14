/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 00:12:07 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/15 00:22:19 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* ****************************** CONSTRUCTORS ****************************** */
Form::Form(void):
	_name("DefaultForm"),
	_gradeSign()
{

}

Form::Form(std::string name, int grade)
{
	
}

Form::Form(const Form& form)
{

}

/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
Form&	Form::operator=(const Form& form)
{

}

/* ******************************* DESTRUCTOR ******************************* */
~Form(void);
/* **************************** MEMBER FUNCTIONS **************************** */


/* ******************************* EXCEPTIONS ******************************* */
const char*	Form::GradeTooHighException::what(void) const throw()
{
	return ("[What] Bureaucrat: Error! Grade too high");
}

const char*	Form::GradeTooLowException::what(void) const throw()
{
	return ("[What] Bureaucrat: Error! Grade too low");
}
