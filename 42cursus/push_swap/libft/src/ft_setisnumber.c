/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setisnumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:24:16 by rgallego          #+#    #+#             */
/*   Updated: 2022/08/22 19:24:24 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * decides if a set is numerical.
 * INPUT:	char *str
 * OUTPUT:	int	:	1	numerical
 *					0	non numerical
 */
int	ft_setisnumber(char **set)
{
	int	cnt;

	if (!set)
		return (0);
	cnt = 0;
	while (set[cnt] && ft_strisnumber(set[cnt]))
		cnt++;
	if (set[cnt])
		return (0);
	return (1);
}
