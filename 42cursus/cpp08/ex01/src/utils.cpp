/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:56:47 by rgallego          #+#    #+#             */
/*   Updated: 2023/12/22 20:06:28 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

int	incGenerator(int i)
{
	return (++i);
}

int	randGenerator(int i)
{
	(void)i;
	return (std::rand() % (RAND_RANGE * 2) - RAND_RANGE);
}
