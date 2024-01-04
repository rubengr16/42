/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:20:30 by rgallego          #+#    #+#             */
/*   Updated: 2024/01/04 12:36:36 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERRYCREATIONFORM_HPP
# define SHRUBBERRYCREATIONFORM_HPP

# include <fstream>
# include "AForm.hpp"

# define SCF_NAME "ShrubberyCreationForm"
# define SCF_SIGN_GRADE 145
# define SCF_EXECUTE_GRADE 137

class ShrubberyCreationForm: public AForm
{
	public:
/* ****************************** CONSTRUCTORS ****************************** */
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& sCForm);
/* ******************************* DESTRUCTOR ******************************* */
		~ShrubberyCreationForm();
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		ShrubberyCreationForm&	operator=(
			const ShrubberyCreationForm& sCForm);
/* **************************** MEMBER FUNCTIONS **************************** */
		static AForm*			factory(const std::string& target);
		void					execute(void) const;
/* ******************************* EXCEPTIONS ******************************* */
	class	FailedOpenException: public std::exception
	{
		public:
			virtual const char*	what(void) const throw();
	};
};

#endif
