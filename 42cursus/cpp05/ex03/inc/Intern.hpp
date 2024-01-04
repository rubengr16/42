/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:46:53 by rgallego          #+#    #+#             */
/*   Updated: 2024/01/04 12:36:32 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

typedef	AForm* (*t_factoryPtr)(const std::string& target);

class Intern
{
	private:
		const static t_factoryPtr	_formOptions[];
/* ****************************** CONSTRUCTORS ****************************** */
		Intern(const Intern& intern);

	public:
		Intern(void);
/* ******************************* DESTRUCTOR ******************************* */
		~Intern();
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		Intern&	operator=(const Intern& intern);
/* **************************** MEMBER FUNCTIONS **************************** */
		AForm*	makeForm(const std::string& name,
			const std::string& target);
/* ******************************* EXCEPTIONS ******************************* */
	class	FormNotFoundException: public std::exception
	{
		public:
			virtual const char*	what(void) const throw();
	};
};


#endif
