/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:28:41 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/28 12:46:32 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <cstdlib>
# include <limits>
# include <vector>
# include <algorithm>

class Span
{
	private:
		unsigned int		_size;
		std::vector<int>	_vector;

	public:
/* ****************************** CONSTRUCTORS ****************************** */
		Span(void);
		Span(unsigned int size);
		Span(const Span& span);
/* ******************************* DESTRUCTOR ******************************* */
		~Span(void);
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		Span&					operator=(const Span& span);
/* **************************** MEMBER FUNCTIONS **************************** */
		int						longestSpan(void);
		int						shortestSpan(void);
		void					addNumber(int nb);
		unsigned int			getSize(void) const;
		const std::vector<int>&	getVector(void) const;
/* ******************************* EXCEPTIONS ******************************* */
	class VectorIsFullException: public std::exception
	{
		public:
			virtual const char*	what(void) const throw();
	};

	class NoEnoughElemsException: public std::exception
	{
		public:
			virtual const char*	what(void) const throw();
	};
};

#endif
