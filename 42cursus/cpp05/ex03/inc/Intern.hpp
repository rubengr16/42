/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:46:53 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/18 13:01:14 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
	private:
/* ****************************** CONSTRUCTORS ****************************** */
		Intern(const Intern& intern);

	public:
		Intern(void);
/* ******************************* DESTRUCTOR ******************************* */
		~Intern();
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		Intern&	operator=(const Intern& intern);
/* **************************** MEMBER FUNCTIONS **************************** */
		void	makeForm(const std::string& formName,
			const std::string& formTarget);
};


#endif
