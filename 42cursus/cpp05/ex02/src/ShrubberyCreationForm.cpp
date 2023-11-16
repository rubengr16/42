/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:20:30 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/16 14:34:44 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERRYCREATIONFORM_HPP
# define SHRUBBERRYCREATIONFORM_HPP

# include "AForm.hpp"

# define SIGN_GRADE 145
# define EXECUTE_GRADE 137

class ShrubberyCreationForm: public AForm
{
	public:
/* ****************************** CONSTRUCTORS ****************************** */
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(
			const ShrubberyCreationForm& sCForm);
/* ******************************* DESTRUCTOR ******************************* */
		~ShrubberyCreationForm();
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		ShrubberyCreationForm&	operator=(
			const ShrubberyCreationForm& sCForm);
/* **************************** MEMBER FUNCTIONS **************************** */
		void					execute(const Bureaucrat& bureaucrat);
};



#endif
