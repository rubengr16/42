/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 22:17:53 by rgallego          #+#    #+#             */
/*   Updated: 2023/12/27 01:27:57 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <deque>
# include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack: public std::stack<T, Container>
{
	public:
/* ****************************** CONSTRUCTORS ****************************** */
		MutantStack(void):
			std::stack<T, Container>()
		{
			std::cout << "[Default Constructor]: MutantStack<>: has been created"
				<< std::endl;
		}

		MutantStack(const MutantStack& mutantStack):
			std::stack<T, Container>(mutantStack)
		{
			std::cout << "[Copy Constructor]: MutantStack<>: has been created"
				<< std::endl;
		}

/* ******************************* DESTRUCTOR ******************************* */
		~MutantStack(void)
		{
			std::cout << "[Destructor]: MutantStack<>: is being destroyed"
				<< std::endl;
		}

/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		MutantStack&	operator=(const MutantStack& mutantStack)
		{
			if (this == &mutantStack)
				return (*this);
			*this = mutantStack;
			std::cout << "[Copy Constructor]: MutantStack<>: has been created"
				<< std::endl;
			return (*this);
		}

/* *************************** ITERATOR FUNCTIONS ************************** */
		typedef typename Container::iterator iterator;
		typedef typename Container::const_iterator const_iterator;
		typedef typename Container::reverse_iterator reverse_iterator;
		typedef typename Container::const_reverse_iterator const_reverse_iterator;

		iterator begin(void)
		{
			return (this->c.begin());
		}

		const_iterator begin(void) const
		{
			return (this->c.begin());
		}

		iterator end(void)
		{
			return (this->c.end());
		}

		const_iterator end(void) const
		{
			return (this->c.end());
		}

		/**
		 * Reverse iterators:
		 * 	- rbegin:	returns an iterator to the last element and previous
		 * 				elements can be accessed by incrementing it.
		 * 				NOTE:	by incrementing it and accessing to the element
		 * 						a segfault will be caused.
		 * 	- rend:		returns an iterator to the first element and next
		 * 				elements can be accessed by decrementing it.
		 * 				NOTE:	by decrementing it and accessing to the element
		 * 						a segfault will be caused.
		 */
		reverse_iterator rbegin(void)
		{
			return (this->c.rbegin());
		}

		const_reverse_iterator rbegin(void) const
		{
			return (this->c.rbegin());
		}

		reverse_iterator rend(void)
		{
			return (this->c.rend());
		}

		const_reverse_iterator rend(void) const
		{
			return (this->c.rend());
		}
};

#endif
