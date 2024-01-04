/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:28:41 by rgallego          #+#    #+#             */
/*   Updated: 2024/01/04 12:36:53 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <cstdlib>
# include <limits>
# include <vector>
# include <algorithm>

struct	Generator
{
	int	i;
	int	(*f)(int);

	Generator(int (*f)(int)):
		i(0),
		f(f)
	{
	}

	int operator()(void)
	{
		i = f(i);
		return (i);
	}
};

class Span
{
	private:
		unsigned int		_maxSize;
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
		unsigned int			getMaxSize(void) const;
		const std::vector<int>&	getVector(void) const;
		int						longestSpan(void);
		int						shortestSpan(void);
		void					addNumber(int nb);
		void					addNumber(int size, Generator generator);
		void					print(void);
/* ******************************* EXCEPTIONS ******************************* */
	class	VectorIsFullException: public std::exception
	{
		public:
			virtual const char*	what(void) const throw();
	};

	class	NoEnoughElemsException: public std::exception
	{
		public:
			virtual const char*	what(void) const throw();
	};
};

#endif
