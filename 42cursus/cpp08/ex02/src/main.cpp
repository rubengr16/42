/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 22:17:38 by rgallego          #+#    #+#             */
/*   Updated: 2023/12/27 01:29:20 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include "MutantStack.hpp"

int	main(void)
{
	{
		MutantStack<int> mstack;
		
		mstack.push(5);
		mstack.push(17);
		
		std::cout << mstack.top() << std::endl;

		mstack.pop();

		std::cout << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;

		std::cout << "Iterate over Mutant Stack" << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

		std::stack<int> s(mstack);

/* ****************************** EXTRA TESTS ****************************** */
		{
			MutantStack<int> cpyMStack(mstack);
			MutantStack<int> cpyAssignMStack = mstack;
		}
		{
			MutantStack<int>::reverse_iterator rit = mstack.rbegin();
			MutantStack<int>::reverse_iterator rite = mstack.rend();

			std::cout << "Iterate over Mutant Stack backwards" << std::endl;
			while (rit != rite)
			{
				std::cout << *rit << std::endl;
				++rit;
			}
		}
	}

/* ******************************* LIST TESTS ****************************** */
	{
		std::list<int> list;
		
		list.push_back(5);
		list.push_back(17);
		
		std::cout << list.back() << std::endl;

		list.pop_back();

		std::cout << list.size() << std::endl;

		list.push_back(3);
		list.push_back(5);
		list.push_back(737);
		list.push_back(0);

		std::list<int>::iterator it = list.begin();
		std::list<int>::iterator ite = list.end();

		++it;
		--it;

		std::cout << "Iterate over List" << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

/* ****************************** EXTRA TESTS ****************************** */
		{
			std::list<int> cpyList(list);
			std::list<int> cpyAssignList = list;
		}
		{
			std::list<int>::reverse_iterator rit = list.rbegin();
			std::list<int>::reverse_iterator rite = list.rend();

			std::cout << "Iterate over List backwards" << std::endl;
			while (rit != rite)
			{
				std::cout << *rit << std::endl;
				++rit;
			}
		}
	}

/* ************************* MUTANTSTACK LIST TESTS ************************ */
	{
		MutantStack<int, std::list<int> > mstacklist;
		
		mstacklist.push(5);
		mstacklist.push(17);
		
		std::cout << mstacklist.top() << std::endl;

		mstacklist.pop();

		std::cout << mstacklist.size() << std::endl;

		mstacklist.push(3);
		mstacklist.push(5);
		mstacklist.push(737);
		mstacklist.push(0);

		MutantStack<int, std::list<int> >::iterator it = mstacklist.begin();
		MutantStack<int, std::list<int> >::iterator ite = mstacklist.end();

		++it;
		--it;

		std::cout << "Iterate over Mutant Stack List" << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

		std::stack<int, std::list<int> > s(mstacklist);

/* ****************************** EXTRA TESTS ****************************** */
		{
			MutantStack<int, std::list<int> > cpyMStack(mstacklist);
			MutantStack<int, std::list<int> > cpyAssignMStack = mstacklist;
		}
		{
			MutantStack<int, std::list<int> >::reverse_iterator rit =
				mstacklist.rbegin();
			MutantStack<int, std::list<int> >::reverse_iterator rite =
				mstacklist.rend();

			std::cout << "Iterate over Mutant Stack List backwards"
				<< std::endl;
			while (rit != rite)
			{
				std::cout << *rit << std::endl;
				++rit;
			}
		}
	}

	return (0);
}
