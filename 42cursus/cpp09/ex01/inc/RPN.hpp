/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:28:41 by rgallego          #+#    #+#             */
/*   Updated: 2024/01/15 22:42:15 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <sstream>
# include <limits>
# include <stack>

# define ALLOWED_CHARS "0123456789 +-*/"
# define OPERANDS "+-*/"


class RPN
{
	private:
/* ****************************** CONSTRUCTORS ****************************** */
		RPN(void);
		RPN(const RPN& rhs);
/* ******************************* DESTRUCTOR ******************************* */
		~RPN(void);
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		RPN&			operator=(const RPN& rhs);

	public:
/* **************************** MEMBER FUNCTIONS **************************** */
		static float	calculate(std::string str);
/* ******************************* EXCEPTIONS ******************************* */
	class	ARPNException: public std::exception
	{
		public:
			virtual const char*	what(void) const throw() = 0;
	};
	
	class	InvalidCharactersException: public ARPNException
	{
		public:
			virtual const char*	what(void) const throw();
	};

	class	NotEnoughNumbersException: public ARPNException
	{
		public:
			virtual const char*	what(void) const throw();
	};

	class	NotEnoughOperandsException: public ARPNException
	{
		public:
			virtual const char*	what(void) const throw();
	};

	class	OutOfRangeResultException: public ARPNException
	{
		public:
			virtual const char*	what(void) const throw();
	};

	class	OutOfRangeOperatorException: public ARPNException
	{
		public:
			virtual const char*	what(void) const throw();
	};
};

#endif
