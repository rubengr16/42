/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:47:05 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/18 13:01:35 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/* ****************************** CONSTRUCTORS ****************************** */
Intern::Intern(void)
{
	std::cout << "[Default Constructor] PresidentialPardonForm:";
}

Intern::Intern(const Intern& intern)
{
	std::cout << "[Copy Constructor] PresidentialPardonForm:";

}

/* ******************************* DESTRUCTOR ******************************* */
Intern::~Intern()
{
	std::cout << "[Destructor] PresidentialPardonForm:";
}

/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
Intern&	Intern::operator=(const Intern& intern)
{
	std::cout << "[Copy Assignment] PresidentialPardonForm:";
}

/* **************************** MEMBER FUNCTIONS **************************** */
void	Intern::makeForm(const std::string& formName,
	const std::string& formTarget)
{
	
}
