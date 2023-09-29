/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:25:53 by rgallego          #+#    #+#             */
/*   Updated: 2023/09/29 16:08:54 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "zombieGenerator.hpp"

int	main(void)
{
	Zombie	*dynamicZombie = newZombie("dynamicZombie");

	randomChump("staticZombie");
	std::cout << dynamicZombie->getName() << ": I'm still here"
		<< std::endl;
	delete dynamicZombie;
	return (0);
}
