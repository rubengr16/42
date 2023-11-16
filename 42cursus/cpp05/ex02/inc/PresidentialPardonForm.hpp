/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:20:30 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/16 14:37:12 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

# define SIGN_GRADE 145
# define EXECUTE_GRADE 137

class PresidentialPardonForm: public AForm
{
	public:
/* ****************************** CONSTRUCTORS ****************************** */
		PresidentialPardonForm(void);
		PresidentialPardonForm(
			const PresidentialPardonForm& pPForm);
/* ******************************* DESTRUCTOR ******************************* */
		~PresidentialPardonForm();
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		PresidentialPardonForm&	operator=(
			const PresidentialPardonForm& pPForm);
/* **************************** MEMBER FUNCTIONS **************************** */
		void					execute(const Bureaucrat& bureaucrat);
};



#endif
