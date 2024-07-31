/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:33:12 by rgallego          #+#    #+#             */
/*   Updated: 2024/07/31 11:28:08 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
/* ******************************** EXAMPLE 1 ******************************* */
	Form	form;

	std::cout << "Form created:" << std::endl;
	std::cout << form << std::endl;
/* ******************************** EXAMPLE 2 ******************************* */
	{
		std::cout << "THIS IS GOING TO FAIL: GRADE TOO LOW" << std::endl
			<< "----------------------------------------------------" << std::endl;
		try
		{
			Form lowForm("lowForm", 151, 4);
		}
		catch(const Form::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl
				<< "----------------------------------------------------"
				<< std::endl;
		}
	}
	{
		std::cout << "THIS IS GOING TO FAIL: GRADE TOO LOW" << std::endl
			<< "----------------------------------------------------" << std::endl;
		try
		{
			Form lowForm("lowForm", 4, 151);
		}
		catch(const Form::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl
				<< "----------------------------------------------------"
				<< std::endl;
		}
	}
	{
		std::cout << "THIS IS GOING TO FAIL: GRADE TOO LOW" << std::endl
			<< "----------------------------------------------------" << std::endl;
		try
		{
			Form lowForm("lowForm", 151, 151);
		}
		catch(const Form::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl
				<< "----------------------------------------------------"
				<< std::endl;
		}
	}
	{
		std::cout << "THIS IS GOING TO FAIL: GRADE TOO HIGH" << std::endl
			<< "----------------------------------------------------" << std::endl;
		try
		{
			Form highForm("highForm", 0, 149);
		}
		catch(const Form::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl
				<< "----------------------------------------------------"
				<< std::endl;
		}
	}
/* ******************************** EXAMPLE 3 ******************************* */
	{
		Form	form2(form);
		Form	form3 = form;
	}
/* ******************************** EXAMPLE 4 ******************************* */
	{
		Form toBeSigned("ToBeSigned", 42, 42);
		
		std::cout << "FORM TO BE SIGNED CREATED" << std::endl
			<< "----------------------------------------------------"
			<< std::endl;
		std::cout << "NAME: " << toBeSigned.getName() << std::endl
			<< "SIGNED: " << toBeSigned.getSigned() << std::endl
			<< "GRADE SIGN: " << toBeSigned.getGradeSign() << std::endl
			<< "GRADE EXECUTE: " << toBeSigned.getGradeExecute() << std::endl
			<< "----------------------------------------------------"
			<< std::endl;

		Bureaucrat	signer("signer", MAX_GRADE);

		std::cout << "SIGNER BUREAUCRAT CREATED" << std::endl
			<< "----------------------------------------------------"
			<< std::endl;
		std::cout << "FORM IS BEING SIGNED" << std::endl
			<< "----------------------------------------------------"
			<< std::endl;
		signer.signForm(toBeSigned);
		std::cout << "----------------------------------------------------"
			<< std::endl << "NAME: " << toBeSigned.getName() << std::endl
			<< "SIGNED: " << toBeSigned.getSigned() << std::endl
			<< "GRADE SIGN: " << toBeSigned.getGradeSign() << std::endl
			<< "GRADE EXECUTE: " << toBeSigned.getGradeExecute() << std::endl
			<< "----------------------------------------------------"
			<< std::endl;

		Bureaucrat	imposibleSigner;
		std::cout << "FORM IS BEING SIGNED" << std::endl
			<< "----------------------------------------------------"
			<< std::endl;
		imposibleSigner.signForm(toBeSigned);
		std::cout << "----------------------------------------------------"
			<< std::endl;
	}
	return (0);
}
