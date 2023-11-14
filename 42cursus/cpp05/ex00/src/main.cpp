/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:33:12 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/15 00:09:06 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
/* ******************************** EXAMPLE 1 ******************************* */
	Bureaucrat	bureaucrat;

	std::cout << "Bureaucrat created:" << std::endl;
	std::cout << bureaucrat << std::endl;
	std::cout << "THIS IS GOING TO FAIL: GRADE TOO LOW" << std::endl
		<< "----------------------------------------------------" << std::endl;
	try
	{
		bureaucrat.decrementGrade();
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl
			<< "----------------------------------------------------"
			<< std::endl;
	}

	std::cout << "THIS IS GOING TO FAIL: GRADE TOO HIGH" << std::endl
		<< "----------------------------------------------------" << std::endl;
	try
	{
		bureaucrat.setGrade(0);
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl
			<< "----------------------------------------------------"
			<< std::endl;
	}
/* ******************************** EXAMPLE 2 ******************************* */
	{
		Bureaucrat bureaucrat2(bureaucrat);

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
