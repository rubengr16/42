/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 22:17:53 by rgallego          #+#    #+#             */
/*   Updated: 2024/01/17 21:42:14 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include "IntegerList.hpp"
# include "IntegerVector.hpp"

class	PmergeMe
{
	private:
/* ****************************** CONSTRUCTORS ****************************** */
		PmergeMe(void);
		PmergeMe(const PmergeMe& rhs);
/* ******************************* DESTRUCTOR ******************************* */
		~PmergeMe(void);
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		PmergeMe&	operator=(const PmergeMe& rhs);
	public:
/* **************************** MEMBER FUNCTIONS **************************** */
		static  void		mergesort(IntegerList& integerList);
		static  void		mergesort(IntegerVector& integerList);
};

#endif
