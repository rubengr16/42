/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 22:17:53 by rgallego          #+#    #+#             */
/*   Updated: 2024/01/18 14:31:00 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include "IntegerList.hpp"
# include <vector>

class	PmergeMe
{
	private:
		IntegerList					_list;
		std::vector<unsigned int>	_vector;
		

	public:
/* ****************************** CONSTRUCTORS ****************************** */
		PmergeMe(void);
		PmergeMe(char** values, int size);
		PmergeMe(const PmergeMe& rhs);
/* ******************************* DESTRUCTOR ******************************* */
		~PmergeMe(void);
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		PmergeMe&							operator=(const PmergeMe& rhs);
/* **************************** MEMBER FUNCTIONS **************************** */
		const IntegerList&					getList(void) const;
		const std::vector<unsigned int>&	getVector(void) const;
		void								mergesortList(void);
		void								mergesortVector(void);
/* ******************************* EXCEPTIONS ******************************* */
	class	WrongNumberException
	{
		public:
			virtual const char*	what(void) const throw();
	};

	class	WrongNumberOfArgumentsException
	{
		public:
			virtual const char*	what(void) const throw();
	};
};

#endif
