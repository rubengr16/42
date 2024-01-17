/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 22:17:38 by rgallego          #+#    #+#             */
/*   Updated: 2024/01/17 21:49:31 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PmergeMe.hpp"
#include "IntegerList.hpp"
#include "IntegerVector.hpp"

int	main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cout << "Error: only one argument was given (the program name)."
			<< "Plaease, use: ./PmergeMe <1..N numbers>." << std::endl;
		return (1);
	}
	IntegerList l(&argv[VALUES_START]);
	std::cout << "Before: ";
	for (IntegerList::iterator it = l.begin(); it != l.end(); it++)
		std::cout << *it << " ";
	PmergeMe::mergesort(l);
	std::cout << "-------------------------" << std::endl;
	for (IntegerList::iterator it = l.begin(); it != l.end(); it++)
		std::cout << *it << std::endl;
	return (0);
}
