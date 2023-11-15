/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:33:12 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/15 17:49:45 by rgallego         ###   ########.fr       */
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
/* ******************************** EXAMPLE 3 ******************************* */
	{
		std::cout << "THIS IS GOING TO FAIL: GRADE TOO HIGH" << std::endl
			<< "----------------------------------------------------" << std::endl;
		try
		{
			Form highForm("highForm", 0, 4);
		}
		catch(const Form::GradeTooHighException& e)
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
			Form highForm("highForm", 4, 0);
		}
		catch(const Form::GradeTooHighException& e)
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
			Form highForm("highForm", 0, 0);
		}
		catch(const Form::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl
				<< "----------------------------------------------------"
				<< std::endl;
		}
	}
/* ******************************** EXAMPLE 4 ******************************* */
	{
		Form bureaucrat2(bureaucrat);

		std::cout << "COPY CONSTRUCTED BUREAUCRAT:" << std::endl
			<< "NAME: " << bureaucrat2.getName() << std::endl
			<< "GRADE: " << bureaucrat2.getGrade() << std::endl
			<< "----------------------------------------------------"
			<< std::endl;
		std::cout << "SET GRADE TO MAX" << std::endl
			<< "----------------------------------------------------"
			<< std::endl;
		bureaucrat2.setGrade(1);
		std::cout << "SET GRADE DONE:" << std::endl
			<< "NAME: " << bureaucrat2.getName() << std::endl
			<< "GRADE: " << bureaucrat2.getGrade() << std::endl
			<< "----------------------------------------------------"
			<< std::endl;
		std::cout << "THIS IS GOING TO FAIL: GRADE TOO HIGH" << std::endl
			<< "----------------------------------------------------"
			<< std::endl;
		try
		{
			bureaucrat2.incrementGrade();
		}
		catch(const Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl
				<< "----------------------------------------------------"
				<< std::endl;
		}
	}
/* ******************************** EXAMPLE 3 ******************************* */
	{
		Bureaucrat bureaucrat3("MaxBureaucrat", MAX_GRADE);
		Bureaucrat bureaucrat4("MinBureaucrat", MIN_GRADE);

		std::cout << "THIS IS GOING TO FAIL: GRADE TOO HIGH" << std::endl
			<< "----------------------------------------------------"
			<< std::endl;
		try
		{
			Bureaucrat bureaucrat5("ERRORTooLOWBureaucrat", MIN_GRADE + 1);
		}
		catch(const Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl
				<< "----------------------------------------------------"
				<< std::endl;
		}
		std::cout << "THIS IS GOING TO FAIL: GRADE TOO HIGH" << std::endl
			<< "----------------------------------------------------"
			<< std::endl;
		try
		{
			Bureaucrat bureaucrat6("ERRORTooHIGHBureaucrat", MAX_GRADE - 1);
		}
		catch(const Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl
				<< "----------------------------------------------------"
				<< std::endl;
		}
	}
	return (0);
}
