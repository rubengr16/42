/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AContainer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:39:15 by rgallego          #+#    #+#             */
/*   Updated: 2024/01/16 23:54:02 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACONTAINER_HPP
# define ACONTAINER_HPP

# include <sstream>
# include <cerrno>
# include <cmath>
# include <limits>

template <typename T<unsigned int> >
class AContainer
{
	protected:
/* ****************************** CONSTRUCTORS ****************************** */
		AContainer(void);
		AContainer(char** values);
		AContainer(const AContainer& rhs);
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		AContainer&				operator=(const AContainer& rhs);

	public:
/* ******************************* DESTRUCTOR ******************************* */
		virtual ~AContainer(void);
/* **************************** MEMBER FUNCTIONS **************************** */
		virtual unsigned int&	at(size_t n) = 0;
/* ******************************* EXCEPTIONS ******************************* */
	class	OutOfRangeResultException
	{
		public:
			virtual const char*	what(void) const throw();
	};
};

#endif
