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

#ifndef INTEGERVECTOR
# define INTEGERVECTOR

# include <vector>
# include <sstream>
# include <cerrno>		// ERANGE
# include <cmath>		// HUGE_VALL
# include <limits>		// std::numeric_limits
# include <stdexcept>	// std::out_of_range
# include "AContainer.hpp"

class	IntegerVector: public std::vector<unsigned int>, public AContainer
{
	public:
/* ****************************** CONSTRUCTORS ****************************** */
		IntegerVector(void);
		IntegerVector(size_t n);
		IntegerVector(char** values);
		IntegerVector(const IntegerVector& rhs);
/* ******************************* DESTRUCTOR ******************************* */
		~IntegerVector(void);
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		IntegerVector&	operator=(const IntegerVector& rhs);
/* **************************** MEMBER FUNCTIONS **************************** */
		unsigned int&	get(size_t n);
};

# endif
