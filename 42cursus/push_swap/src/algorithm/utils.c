/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:46:17 by rgallego          #+#    #+#             */
/*   Updated: 2023/02/22 12:21:45 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

int	calc_median(int min, int max)
{
	return (((max + min) / 2) + ((max + min) % 2));
}

int	on_range(int min, int max, int value)
{
	return (min <= value && value <= max);
}
