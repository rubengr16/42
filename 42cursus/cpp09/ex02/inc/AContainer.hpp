/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AContainer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:39:15 by rgallego          #+#    #+#             */
/*   Updated: 2024/01/17 21:47:36 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACONTAINER_HPP
# define ACONTAINER_HPP

# include <sstream>
# include <cerrno>
# include <cmath>
# include <limits>

# define VALUES_START 1

class AContainer
{
	protected:
/* ****************************** CONSTRUCTORS ****************************** */
		AContainer(void);
		AContainer(const AContainer& rhs);
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		AContainer&				operator=(const AContainer& rhs);

	public:
/* ******************************* DESTRUCTOR ******************************* */
		virtual ~AContainer(void);
/* **************************** MEMBER FUNCTIONS **************************** */
		unsigned int	get_number(char *str);
		virtual unsigned int&	get(size_t n) = 0;
/* ******************************* EXCEPTIONS ******************************* */
	class	WrongNumberException
	{
		public:
			virtual const char*	what(void) const throw();
	};

	class	TooMuchNumbersException
	{
		public:
			virtual const char*	what(void) const throw();
	};
};

#endif
