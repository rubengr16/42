/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:33:12 by rgallego          #+#    #+#             */
/*   Updated: 2024/07/31 14:10:11 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	Bureaucrat	bureaucrat("Bureaucrat", MAX_GRADE);
/* ************************ PRESIDENTIAL PARDON FORM ************************* */
	{
		PresidentialPardonForm	unSigned;
		PresidentialPardonForm	pPForm("pardoned");

		std::cout << "THIS IS GOING TO FAIL: NOT SIGNED" << std::endl
			<< "----------------------------------------------------"
			<< std::endl;
		try
		{
			unSigned.execute(bureaucrat);
		}
		catch(const AForm::NotSignedException& e)
		{
			std::cerr << e.what() << std::endl
				<< "----------------------------------------------------"
				<< std::endl;
		}
		bureaucrat.signForm(pPForm);
		std::cout << "----------------------------------------------------"
			<< std::endl;
		pPForm.execute(bureaucrat);
	}
	std::cout << "===================================================="
		<< "====================================================" << std::endl;
/* ************************ SHRUBBERY CREATION FORM ************************* */
	{
		ShrubberyCreationForm	unSigned;
		ShrubberyCreationForm	sCForm("home");

		std::cout << "THIS IS GOING TO FAIL: NOT SIGNED" << std::endl
			<< "----------------------------------------------------"
			<< std::endl;
		try
		{
			unSigned.execute(bureaucrat);
		}
		catch(const AForm::NotSignedException& e)
		{
			std::cerr << e.what() << std::endl
				<< "----------------------------------------------------"
				<< std::endl;
		}
		bureaucrat.signForm(sCForm);
		std::cout << "----------------------------------------------------"
			<< std::endl;
		sCForm.execute(bureaucrat);
	}
	std::cout << "===================================================="
		<< "====================================================" << std::endl;
/* ************************* ROBOTOMY REQUEST FORM ************************* */
	{
		unsigned int		i;
		RobotomyRequestForm	unSigned;
		RobotomyRequestForm	rRForm("robotomized");
		

		std::cout << "THIS IS GOING TO FAIL: NOT SIGNED" << std::endl
			<< "----------------------------------------------------"
			<< std::endl;
		try
		{
			unSigned.execute(bureaucrat);
		}
		catch(const AForm::NotSignedException& e)
		{
			std::cerr << e.what() << std::endl
				<< "----------------------------------------------------"
				<< std::endl;
		}
		bureaucrat.signForm(rRForm);
		std::cout << "----------------------------------------------------"
			<< std::endl;
		for (i = 0; i < 10; i++)
			rRForm.execute(bureaucrat);
	}
/* ***************************** EXECUTE TEST ****************************** */
	{
		RobotomyRequestForm	rRForm("robotomized");
		Bureaucrat			simpleBureaucrat;

		bureaucrat.signForm(rRForm);
		std::cout << "THIS IS GOING TO FAIL: GRADE TOO LOW TO SIGN"
			<< std::endl
			<< "----------------------------------------------------"
			<< std::endl;
		try
		{
			rRForm.execute(simpleBureaucrat);
		}
		catch(const AForm::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl
				<< "----------------------------------------------------"
				<< std::endl;
		}
	}
	return (0);
}
