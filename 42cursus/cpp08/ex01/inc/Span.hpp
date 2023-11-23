/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:28:41 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/23 22:24:42 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
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
/* ******************************* EXCEPTIONS ******************************* */
	class ElemNotFoundException: public std::exception
	{
		public:
			virtual const char*	what(void) const throw();
	};
};

#endif
