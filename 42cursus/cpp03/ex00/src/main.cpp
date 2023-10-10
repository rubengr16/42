/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:24:39 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/10 19:03:41 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	blabla("blabla");
	ClapTrap	wiwi(blabla);
	ClapTrap	runrun("runrun");

	std::cout << "ALL CLAPTRAPS CREATED" << std::endl
		<< "----------------------------------------------------" << std::endl;
	runrun = wiwi;
	wiwi.setName("wiwi");
	runrun.setName("runrun");
	std::cout << "ALL CLAPTRAPS SET" << std::endl
		<< "----------------------------------------------------" << std::endl;

	std::cout << "CLAPTRAPS ATTACK!!!" << std::endl
		<< "----------------------------------------------------" << std::endl;
	wiwi.setDamagePts(3);
	runrun.setDamagePts(5);
	
	while (blabla.getHitPts())
	{
		runrun.attack(blabla.getName());
		blabla.takeDamage(runrun.getDamagePts());	
	}

	std::cout << "CLAPTRAP " << blabla.getName() << " IS GOING TO BE REPAIRED"
	<< std::endl << "----------------------------------------------------"
		<< std::endl;
	blabla.beRepaired(50);
	std::cout << "CLAPTRAPS ATTACK!!!" << std::endl
		<< "----------------------------------------------------" << std::endl;
	while (runrun.getEnergyPts() && wiwi.getHitPts())
	{
		runrun.attack(wiwi.getName());
		wiwi.takeDamage(runrun.getDamagePts());
	}

	std::cout << "CLAPTRAP " << runrun.getName() << " IS GOING TO BE REPAIRED"
	<< " UNTIL THEIR ENERGY ENDS"
	<< std::endl << "----------------------------------------------------"
		<< std::endl;
	while (runrun.getEnergyPts())
		runrun.beRepaired(33);

	std::cout << "SCAVTRAPS DESTRUCTION!!!" << std::endl
		<< "----------------------------------------------------" << std::endl;

	return (0);
}
