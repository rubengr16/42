/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:33:45 by rgallego          #+#    #+#             */
/*   Updated: 2024/01/04 12:35:33 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

# define MAX_GRADE 1
# define MIN_GRADE 150

class	Bureaucrat
{
	private:
		const std::string	_name;
		unsigned int		_grade;

	public:
/* ****************************** CONSTRUCTORS ****************************** */
		Bureaucrat(void);
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& bureaucrat);
/* ******************************* DESTRUCTOR ******************************* */
		~Bureaucrat(void);
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		Bureaucrat&			operator=(const Bureaucrat& bureaucrat);
/* **************************** MEMBER FUNCTIONS **************************** */
		const std::string&	getName(void) const;
		unsigned int		getGrade(void) const;
		void				setGrade(unsigned int grade);
		void				incrementGrade(void);
		void				decrementGrade(void);

/* ******************************* EXCEPTIONS ******************************* */
	class	GradeTooHighException: public std::exception
	{
		public:
			virtual const char*	what(void) const throw();
	};
	class	GradeTooLowException: public std::exception
	{
		public:
			virtual const char*	what(void) const throw();
	};
};

/* ************************* INPUT OPERATOR OVERLOAD ************************ */
std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
