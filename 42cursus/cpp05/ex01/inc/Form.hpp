/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 00:11:55 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/15 15:07:29 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

# define MAX_GRADE 1
# define MIN_GRADE 150

class	Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const unsigned int	_gradeSign;
		const unsigned int	_gradeExecute;

	public:
/* ****************************** CONSTRUCTORS ****************************** */
		Form(void);
		Form(std::string name, unsigned int gradeSign,
			unsigned int gradeExecute);
		Form(const Form& form);
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		Form&	operator=(const Form& form);
/* ******************************* DESTRUCTOR ******************************* */
		~Form(void);
/* **************************** MEMBER FUNCTIONS **************************** */
		const std::string&	getName(void) const;
		bool				getSigned(void) const;
		const unsigned int	getGradeSign(void) const;
		const unsigned int	getGradeExecute(void) const;
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

/* ************************ OUTPUT OPERATOR OVERLOAD ************************ */
std::ostream&	operator<<(std::ostream& os, const Form& form);

#endif
