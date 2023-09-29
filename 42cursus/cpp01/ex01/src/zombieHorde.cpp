/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:14:17 by rgallego          #+#    #+#             */
/*   Updated: 2023/09/29 17:00:06 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombieHorde.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	int		i;
	Zombie	*zHorde;

	if (N < 0)
		return (NULL);
	zHorde = new Zombie[N];
	for (i = 0; i < N; i++)
		zHorde[i].setName(name);
	return (zHorde);
}
