/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IntegerList.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:51:01 by rgallego          #+#    #+#             */
/*   Updated: 2024/01/17 19:00:43 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTEGERLIST
# define INTEGERLIST

# include <list>
# include <sstream>
# include <cerrno>		// ERANGE
# include <cmath>		// HUGE_VALL
# include <limits>		// std::numeric_limits
# include <stdexcept>	// std::out_of_range
# include "AContainer.hpp"

class	IntegerList: public std::list<unsigned int>, public AContainer
{
	public:
/* ****************************** CONSTRUCTORS ****************************** */
		IntegerList(void);
		IntegerList(size_t n);
		IntegerList(char** values);
		IntegerList(const IntegerList& rhs);
/* ******************************* DESTRUCTOR ******************************* */
		~IntegerList(void);
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		IntegerList&	operator=(const IntegerList& rhs);
/* **************************** MEMBER FUNCTIONS **************************** */
		unsigned int&	get(size_t n);
};

# endif
