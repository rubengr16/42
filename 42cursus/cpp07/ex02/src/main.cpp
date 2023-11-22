/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:13:14 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/22 21:48:45 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <ctime>
# include <cstdlib>
#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750

int main(int, char **)
{
	Array<int>	numbers(MAX_VAL);
	int			*mirror = new int[MAX_VAL];

	std::srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int	value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
		std::cout << "Copy Assignment and Assignment Operator" << std::endl;
	}
	std::cout << "Copy Assignment and Assignment Operator" << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return (1);
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete[] mirror;
	return 0;
}
