/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 00:11:55 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/15 23:55:40 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class	Bureaucrat;

# define MAX_GRADE 1
# define MIN_GRADE 150

class	AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const unsigned int	_gradeSign;
		const unsigned int	_gradeExecute;

		unsigned int		checkGrade(unsigned int grade);

	public:
/* ****************************** CONSTRUCTORS ****************************** */
		AForm(void);
		AForm(std::string name, unsigned int gradeSign,
			unsigned int gradeExecute);
		AForm(const AForm& form);
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		AForm&				operator=(const AForm& form);
/* ******************************* DESTRUCTOR ******************************* */
		virtual ~AForm(void);
/* **************************** MEMBER FUNCTIONS **************************** */
		const std::string&	getName(void) const;
		bool				getSigned(void) const;
		unsigned int		getGradeSign(void) const;
		unsigned int		getGradeExecute(void) const;
		void				beSigned(const Bureaucrat& bureaucrat);
		virtual void		execute(const Bureaucrat& bureaucrat) const = 0;
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
	class NotSignedException: public std::exception
	{
		public:
			virtual const char*	what(void) const throw();
	};
};

/* ************************* INPUT OPERATOR OVERLOAD ************************ */
std::ostream&	operator<<(std::ostream& os, const AForm& form);

#endif
