/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 22:17:53 by rgallego          #+#    #+#             */
/*   Updated: 2023/12/22 23:01:50 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <deque>
# include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack: std::stack<T, Container>
{
/* ****************************** CONSTRUCTORS ****************************** */
		MutantStack(void):
			std::stack<T, Container>()
		{
			std::cout << "[Default Constructor]: MutantStack<>: has been created"
				<< std::endl;
		}
		MutantStack(const MutantStack& mutantStack)
		{
			// TODO: Complete
			std::cout << "[Copy Constructor]: MutantStack<>: has been created"
				<< std::endl;
		}
/* ******************************* DESTRUCTOR ******************************* */
		~MutantStack(void)
		{
			// TODO: Complete
			std::cout << "[Destructor]: MutantStack<>: is being destroyed"
				<< std::endl;
		}
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		MutantStack&	operator=(const MutantStack& mutantStack)
		{
			if (this == &mutantStack)
				return (*this);
			// TODO: Complete
			std::cout << "[Copy Constructor]: MutantStack<>: has been created"
				<< std::endl;
			return (*this);
		}
/* **************************** MEMBER FUNCTIONS **************************** */
};

#endif
