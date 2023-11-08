/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:25:53 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/03 13:15:08 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "zombieHorde.hpp"

int	main(void)
{
	Zombie		*zHorde;
	int			i;
	
	zHorde = zombieHorde(SIZE, "AZombieHorde");
	if (!zHorde)
		return (1);
	for (i = 0; i < SIZE; i++)
		zHorde[i].announce();
	std::cout << "Let's git a different name for each zombie!!" << std::endl
		<< "Their index will be their name!"
		<< std::endl;
	for (i = 0; i < SIZE; i++)g
		zHorde[i].setName(std::itoa(i));
	delete []zHorde;
	return (0);
}
