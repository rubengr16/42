/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:20:30 by rgallego          #+#    #+#             */
/*   Updated: 2024/07/31 12:23:04 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <ctime>
# include <cstdlib>
# include "AForm.hpp"

# define RRF_NAME "RobotomyRequestForm"
# define RRF_SIGN_GRADE 72
# define RRF_EXECUTE_GRADE 45

class RobotomyRequestForm: public AForm
{
	public:
/* ****************************** CONSTRUCTORS ****************************** */
		RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& rRForm);
/* ******************************* DESTRUCTOR ******************************* */
		~RobotomyRequestForm();
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		RobotomyRequestForm&	operator=(
			const RobotomyRequestForm& rRForm);
/* **************************** MEMBER FUNCTIONS **************************** */
		void					execute(Bureaucrat const & executor) const;
};

#endif
