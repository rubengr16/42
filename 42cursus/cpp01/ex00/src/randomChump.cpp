/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:34:00 by rgallego          #+#    #+#             */
/*   Updated: 2023/09/29 16:05:59 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombieGenerator.hpp"

void	randomChump(std::string name)
{
	Zombie zombie(name);
	zombie.announce();
}
