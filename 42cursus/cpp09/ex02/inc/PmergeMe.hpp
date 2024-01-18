/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 22:17:53 by rgallego          #+#    #+#             */
/*   Updated: 2024/01/18 19:34:52 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <iomanip>
# include <vector>
# include <sstream>		// stringstream
# include <cerrno>		// ERANGE
# include <cmath>		// HUGE_VALL
# include <limits>		// std::numeric_limits
# include <time.h>
# include "IntegerList.hpp"

# define VALUES_START 1
# define PRECISION 3
# define BEFORE "Before "
# define AFTER "After  "

class	PmergeMe
{
	private:
		IntegerList					_list;
		double						_listTime;
		std::vector<unsigned int>	_vector;
		double						_vectorTime;
/* ****************************** CONSTRUCTORS ****************************** */
		PmergeMe(void);
		PmergeMe(const PmergeMe& rhs);
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		PmergeMe&							operator=(const PmergeMe& rhs);

	public:
		PmergeMe(char** values, int size);
/* ******************************* DESTRUCTOR ******************************* */
		~PmergeMe(void);
/* **************************** MEMBER FUNCTIONS **************************** */
		const IntegerList&					getList(void) const;
		const std::vector<unsigned int>&	getVector(void) const;
		static void							mergesortList(IntegerList& list);
		static void							mergesortVector(
			std::vector<unsigned int> vector);
/* ******************************* EXCEPTIONS ******************************* */
	class	APmergeMeException: public std::exception
	{
		public:
			virtual const char*	what(void) const throw() = 0;
	};

	class	WrongNumberException: public APmergeMeException
	{
		public:
			virtual const char*	what(void) const throw();
	};

	class	WrongNumberOfArgumentsException: public APmergeMeException
	{
		public:
			virtual const char*	what(void) const throw();
	};
};

#endif
