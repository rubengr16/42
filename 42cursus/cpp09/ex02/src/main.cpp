/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 22:17:38 by rgallego          #+#    #+#             */
/*   Updated: 2024/01/18 19:35:26 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PmergeMe.hpp"
#include "IntegerList.hpp"

int	main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cout << "Error: only one argument was given (the program name)."
			<< "Plaease, use: ./PmergeMe <1..N numbers>." << std::endl;
		return (1);
	}
	try
	{
		PmergeMe pmergeMe(&argv[VALUES_START], argc - 1);
	}
	catch(const PmergeMe::APmergeMeException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return (0);
}
