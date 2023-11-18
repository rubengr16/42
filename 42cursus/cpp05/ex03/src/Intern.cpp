/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:47:05 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/18 14:54:52 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

const t_factoryPtr	Intern::_formOptions[] =
{
	PresidentialPardonForm::factory,
	RobotomyRequestForm::factory,
	ShrubberyCreationForm::factory
};

/* ****************************** CONSTRUCTORS ****************************** */
Intern::Intern(void)
{
	std::cout << "[Default Constructor] Intern: has been created" << std::endl;
}

Intern::Intern(const Intern& intern)
{
	(void)intern;
	std::cout << "[Copy Constructor] Intern: shall never be used to create "
		<< "interns";

}

/* ******************************* DESTRUCTOR ******************************* */
Intern::~Intern()
{
	std::cout << "[Destructor] Intern: is being destroyed";
}

/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
Intern&	Intern::operator=(const Intern& intern)
{
	(void)intern;
	std::cout << "[Copy Assignment Operator] Intern: shall never be used to "
		"create interns" << std::endl;
	return (*this);
}

/* **************************** MEMBER FUNCTIONS **************************** */
AForm*	Intern::makeForm(const std::string& name, const std::string& target)
{
	unsigned int	i;

	while (i < 3 && name.compare(PPF_NAME) && name.compare(RRF_NAME)
		&& name.compare(SCF_NAME))
		i++;
	if (i == 3)
	{
		std::cout << "[What] Intern: Error! 404: " << name << " not found"
			<< std::endl;
		throw Intern::FormNotFoundException();
	}
	std::cout << "Intern creates " << name << std::endl;
	return (_formOptions[i](target));
}

/* ******************************* EXCEPTIONS ******************************* */
const char*	Intern::FormNotFoundException::what(void) const throw()
{
	return ("[What] Intern: Error! 404: AForm not found");
}
