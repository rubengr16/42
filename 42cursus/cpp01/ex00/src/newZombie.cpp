/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:33:47 by rgallego          #+#    #+#             */
/*   Updated: 2023/09/29 16:17:07 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombieGenerator.hpp"

Zombie	*newZombie(std::string name)
{
	Zombie *zombie = new Zombie;
	zombie->setName(name);
	zombie->announce();
	return (zombie);
}
