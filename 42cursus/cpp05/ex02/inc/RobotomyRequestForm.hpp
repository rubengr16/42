/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:20:30 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/16 14:36:51 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

# define SIGN_GRADE 72
# define EXECUTE_GRADE 45

class RobotomyRequestForm: public AForm
{
	public:
/* ****************************** CONSTRUCTORS ****************************** */
		RobotomyRequestForm(void);
		RobotomyRequestForm(
			const RobotomyRequestForm& rRForm);
/* ******************************* DESTRUCTOR ******************************* */
		~RobotomyRequestForm();
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		RobotomyRequestForm&	operator=(
			const RobotomyRequestForm& rRForm);
/* **************************** MEMBER FUNCTIONS **************************** */
		void					execute(const Bureaucrat& bureaucrat);
};



#endif
