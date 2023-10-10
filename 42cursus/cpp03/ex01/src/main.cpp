/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:24:39 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/10 19:03:29 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	blabla("blabla");
	ScavTrap	wiwi(blabla);
	ScavTrap	runrun("runrun");

	std::cout << "ALL SCAVTRAPS CREATED" << std::endl
		<< "----------------------------------------------------" << std::endl;
	runrun = wiwi;
	wiwi.setName("wiwi");
	runrun.setName("runrun");
	std::cout << "ALL SCAVTRAPS SET" << std::endl
		<< "----------------------------------------------------" << std::endl;

	std::cout << "SCAVTRAPS ATTACK!!!" << std::endl
		<< "----------------------------------------------------" << std::endl;
	wiwi.setDamagePts(3);
	runrun.setDamagePts(5);
	
	while (blabla.getHitPts())
	{
		runrun.attack(blabla.getName());
		blabla.takeDamage(runrun.getDamagePts());	
	}

	std::cout << "SCAVTRAP " << blabla.getName() << " IS GOING TO BE REPAIRED"
	<< std::endl << "----------------------------------------------------"
		<< std::endl;
	blabla.beRepaired(50);
	std::cout << "SCAVTRAPS ATTACK!!!" << std::endl
		<< "----------------------------------------------------" << std::endl;
	while (runrun.getEnergyPts() && wiwi.getHitPts())
	{
		runrun.attack(wiwi.getName());
		wiwi.takeDamage(runrun.getDamagePts());
	}

	std::cout << "SCAVTRAP " << runrun.getName() << " IS GOING TO BE REPAIRED"
	<< " UNTIL THEIR ENERGY ENDS"
	<< std::endl << "----------------------------------------------------"
		<< std::endl;
	while (runrun.getEnergyPts())
		runrun.beRepaired(33);

	std::cout << "SCAVTRAPS GATE KEEPER MODE" << std::endl
		<< "----------------------------------------------------" << std::endl;
	runrun.guardGate();

	std::cout << "SCAVTRAPS DESTRUCTION!!!" << std::endl
		<< "----------------------------------------------------" << std::endl;

	return (0);
}
