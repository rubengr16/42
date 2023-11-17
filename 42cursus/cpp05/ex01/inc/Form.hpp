/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 00:11:55 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/17 18:02:23 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class	Bureaucrat;

# define MAX_GRADE 1
# define MIN_GRADE 150

class	Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const unsigned int	_gradeSign;
		const unsigned int	_gradeExecute;

		unsigned int	checkGrade(unsigned int grade);

	public:
/* ****************************** CONSTRUCTORS ****************************** */
		Form(void);
		Form(const std::string& name, unsigned int gradeSign,
			unsigned int gradeExecute);
		Form(const Form& form);
/* ******************************* DESTRUCTOR ******************************* */
		~Form(void);
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		Form&				operator=(const Form& form);
/* **************************** MEMBER FUNCTIONS **************************** */
		const std::string&	getName(void) const;
		bool				getSigned(void) const;
		unsigned int		getGradeSign(void) const;
		unsigned int		getGradeExecute(void) const;
		void				beSigned(const Bureaucrat& bureaucrat);
/* ******************************* EXCEPTIONS ******************************* */
	class GradeTooHighException: public std::exception
	{
		public:
			virtual const char*	what(void) const throw();
	};
	class GradeTooLowException: public std::exception
	{
		public:
			virtual const char*	what(void) const throw();
	};
};

/* ************************* INPUT OPERATOR OVERLOAD ************************ */
std::ostream&	operator<<(std::ostream& os, const Form& form);

#endif
