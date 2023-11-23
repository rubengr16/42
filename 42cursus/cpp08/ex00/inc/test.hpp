/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 20:06:53 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/23 20:42:29 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
# define TEST_HPP

# include <iostream>
# include "easyfind.hpp"

# define SIZE 42

template <typename T>
void	test(T& container, const std::string& type)
{
	unsigned int	i;

	std::cout << "----------------------------------------------------"
		<< std::endl;
	std::cout << "BEGIN OF TEST FOR " << type << std::endl;
	for (i = 0; i < SIZE; i++)
		container.push_back(i);
	std::cout << "CONTAINER INITIALIZED WITH VALUES BETWEEN 0 AND " << SIZE - 1
		<< std::endl;
	std::cout << "FAILED TEST: SEARCH ELEM -1" << std::endl;
	try
	{
		*easyfind(container, -1) << std::endl;
	}
	catch(const ElemNotFoundException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "PASSED TEST: SEARCH ELEM 12" << std::endl;
	try
	{
		
		std::cout << "VALUE FOUND: " << *easyfind(container, 12) << std::endl;
	}
	catch(const ElemNotFoundException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "----------------------------------------------------"
		<< std::endl;
}

#endif
