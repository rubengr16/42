/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:24:39 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/12 11:50:07 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	blabla("blabla");
	DiamondTrap	wiwi(blabla);
	DiamondTrap	runrun;

	std::cout << "ALL DIAMONDTRAPS CREATED" << std::endl
		<< "----------------------------------------------------" << std::endl;
	runrun = wiwi;
	wiwi.setName("wiwi");
	runrun.setName("runrun");
	std::cout << "ALL DIAMONDTRAPS SET" << std::endl
		<< "----------------------------------------------------" << std::endl;

	std::cout << "DIAMONDTRAPS ATTACK!!!" << std::endl
		<< "----------------------------------------------------" << std::endl;
	wiwi.setDamagePts(3);
	runrun.setDamagePts(5);
	
	while (blabla.getHitPts())
	{
		runrun.attack(blabla.getName());
		blabla.takeDamage(runrun.getDamagePts());	
	}

	std::cout << "DIAMONDTRAP " << blabla.getName() << " IS GOING TO BE REPAIRED"
	<< std::endl << "----------------------------------------------------"
		<< std::endl;
	blabla.beRepaired(50);
	std::cout << "DIAMONDTRAPS ATTACK!!!" << std::endl
		<< "----------------------------------------------------" << std::endl;
	while (runrun.getEnergyPts() && wiwi.getHitPts())
	{
		runrun.attack(wiwi.getName());
		wiwi.takeDamage(runrun.getDamagePts());
	}

	std::cout << "DIAMONDTRAP " << runrun.getName() << " IS GOING TO BE REPAIRED"
	<< " UNTIL THEIR ENERGY ENDS"
	<< std::endl << "----------------------------------------------------"
		<< std::endl;
	while (runrun.getEnergyPts())
		runrun.beRepaired(33);

	std::cout << "DIAMONDTRAP GATE KEEPER MODE" << std::endl
		<< "----------------------------------------------------" << std::endl;
	runrun.guardGate();

	std::cout << "DIAMONDTRAP HIGH FIVE EVERYONE" << std::endl
		<< "----------------------------------------------------" << std::endl;
	runrun.highFiveGuys();

	std::cout << "DIAMONDTRAP WHO AM I" << std::endl
		<< "----------------------------------------------------" << std::endl;
	runrun.WhoAmI();

	std::cout << "DIAMONDTRAPS DESTRUCTION!!!" << std::endl
		<< "----------------------------------------------------" << std::endl;

	return (0);
}
