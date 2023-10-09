/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:24:39 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/09 22:54:55 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	blabla("blabla");
	ClapTrap	wiwi(blabla);
	ClapTrap	runrun("runrun");

	runrun = wiwi;
	wiwi.setName("wiwi");
	runrun.setName("runrun");

	wiwi.setDamagePts(3);
	runrun.setDamagePts(5);
	
	while (blabla.getHitPts())
	{
		runrun.attack(blabla.getName());
		blabla.takeDamage(runrun.getDamagePts());	
	}
	
	blabla.beRepaired(50);
	
	while (wiwi.getEnergyPts() && blabla.getHitPts())
	{
		wiwi.attack(blabla.getName());
		blabla.takeDamage(wiwi.getDamagePts());
	}

	while (runrun.getEnergyPts())
		runrun.beRepaired(33);

	return (0);
}
