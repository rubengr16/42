/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:45:36 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/21 22:19:28 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

void	pow(int* nb)
{
	*nb = *nb * *nb;
}

void	print(int* nb)
{
	std::cout << *nb << std::endl;
}

void	print(std::string* str)
{
	std::cout << *str << std::endl;
}

void	oneWord(std::string* str)
{
	*str = str->substr(0, str->find(" "));
}

int	main( void )
{
	int	nbArray[] = {1, 2, 3, 4, 5, 6, 7, 8};

	std::cout << "NUMBER ARRAY:" << std::endl;
	::iter(nbArray, sizeof(nbArray) / sizeof(int), print);
	std::cout << "POWERED NUMBER ARRAY:" << std::endl;
	::iter(nbArray, sizeof(nbArray) / sizeof(int), pow);
	::iter(nbArray,  sizeof(nbArray) / sizeof(int), print);

	std::cout << "----------------------------------------------------" 
		<< std::endl << "----------------------------------------------------"
		<< std::endl;

	std::string strArray[] =
	{
		"hello world",
		"I am learning how templates work",
		"I hope you are learning too",
		"have a great time",
		"byeeeee"
	};
	std::cout << "STRING ARRAY:" << std::endl;
	::iter(strArray, sizeof(strArray) / sizeof(std::string), print);
	std::cout << "ONEWORDED STRING ARRAY:" << std::endl;
	::iter(strArray, sizeof(strArray) / sizeof(std::string), oneWord);
	::iter(strArray,  sizeof(strArray) / sizeof(std::string), print);

	return (0);
}
