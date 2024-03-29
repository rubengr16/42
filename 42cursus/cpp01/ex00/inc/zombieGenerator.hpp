/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieGenerator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:59:45 by rgallego          #+#    #+#             */
/*   Updated: 2023/12/02 18:23:57 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEGENERATOR_HPP
# define ZOMBIEGENERATOR_HPP

#include "Zombie.hpp"

void	randomChump(std::string name);
Zombie*	newZombie(std::string name);

#endif
