/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:25:53 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/22 21:36:40 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "zombieHorde.hpp"

int	main(void)
{
	Zombie		*zHorde;
	std::string	names[] = {"One", "Two", "Three", "Four", "Five", "Six"};
	int			i;
	
	zHorde = zombieHorde(SIZE, "AZombieHorde");
	if (!zHorde)
		return (1);
	for (i = 0; i < SIZE; i++)
		zHorde[i].announce();
	std::cout << "Let's git a different name for each zombie!!" << std::endl
		<< "Their index will be their name!"
		<< std::endl;
	for (i = 0; i < SIZE; i++)
		zHorde[i].setName(names[i]);
	delete [] zHorde;
	return (0);
}
