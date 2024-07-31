/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:20:30 by rgallego          #+#    #+#             */
/*   Updated: 2024/07/31 12:23:13 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

# define PPF_NAME "PresidentialPardonForm"
# define PPF_SIGN_GRADE 145
# define PPF_EXECUTE_GRADE 137

class PresidentialPardonForm: public AForm
{
	public:
/* ****************************** CONSTRUCTORS ****************************** */
		PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& pPForm);
/* ******************************* DESTRUCTOR ******************************* */
		~PresidentialPardonForm();
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		PresidentialPardonForm&	operator=(
			const PresidentialPardonForm& pPForm);
/* **************************** MEMBER FUNCTIONS **************************** */
		static AForm*			factory(const std::string& target);
		void					execute(Bureaucrat const & executor) const;
};

#endif
