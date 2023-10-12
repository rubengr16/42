/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:24:39 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/11 23:19:30 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	FragTrap	blabla("blabla");
	FragTrap	wiwi(blabla);
	FragTrap	runrun("runrun");

	std::cout << "ALL FRAGTRAPS CREATED" << std::endl
		<< "----------------------------------------------------" << std::endl;
	runrun = wiwi;
	wiwi.setName("wiwi");
	runrun.setName("runrun");
	std::cout << "ALL FRAGTRAPS SET" << std::endl
		<< "----------------------------------------------------" << std::endl;

	std::cout << "FRAGTRAPS ATTACK!!!" << std::endl
		<< "----------------------------------------------------" << std::endl;
	wiwi.setDamagePts(3);
	runrun.setDamagePts(5);
	
	while (blabla.getHitPts())
	{
		runrun.attack(blabla.getName());
		blabla.takeDamage(runrun.getDamagePts());	
	}

	std::cout << "FRAGTRAP " << blabla.getName() << " IS GOING TO BE REPAIRED"
	<< std::endl << "----------------------------------------------------"
		<< std::endl;
	blabla.beRepaired(50);
	std::cout << "FRAGTRAPS ATTACK!!!" << std::endl
		<< "----------------------------------------------------" << std::endl;
	while (runrun.getEnergyPts() && wiwi.getHitPts())
	{
		runrun.attack(wiwi.getName());
		wiwi.takeDamage(runrun.getDamagePts());
	}

	std::cout << "FRAGTRAP " << runrun.getName() << " IS GOING TO BE REPAIRED"
	<< " UNTIL THEIR ENERGY ENDS"
	<< std::endl << "----------------------------------------------------"
		<< std::endl;
	while (runrun.getEnergyPts())
		runrun.beRepaired(33);

	std::cout << "FRAGTRAP HIGHS FIVE EVERYONE" << std::endl
		<< "----------------------------------------------------" << std::endl;
	runrun.highFiveGuys();

	std::cout << "FRAGTRAPS DESTRUCTION!!!" << std::endl
		<< "----------------------------------------------------" << std::endl;

	return (0);
}
