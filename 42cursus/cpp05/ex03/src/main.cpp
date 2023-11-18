/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:33:12 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/18 14:45:27 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	Bureaucrat		bureaucrat("Bureaucrat", MAX_GRADE);
	Intern			intern;
	AForm*			formObjects[4];
	std::string		forms[] = {PPF_NAME, RRF_NAME, SCF_NAME, "NotFoundForm"};
	std::string		target = "target";
	unsigned int	i;

	for (i = 0; i < 4; i++)
	{
		std::cout << forms[i] << "'s TURN" << std::endl
			<< "----------------------------------------------------"
				<< std::endl;
		try
		{
			formObjects[i] = intern.makeForm(forms[i], target);
			delete formObjects[i];
		}
		catch(const Intern::FormNotFoundException& e)
		{
			std::cerr << e.what() << std::endl
				<< "----------------------------------------------------"
				<< std::endl;
		}
	}
	return (0);
}
