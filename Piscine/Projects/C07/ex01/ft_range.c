/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 12:03:35 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/26 17:32:13 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range_aux(int min, int max)
{
	int	*tab;
	int	size;
	int	i;

	size = max - min;
	tab = (int *)malloc(sizeof(int *) * size);
	if (tab)
	{
		i = 0;
		while (i < size)
		{
			tab[i] = min;
			min++;
			i++;
		}
	}
	return (tab);
}

int	*ft_range(int min, int max)
{
	int	*tab;

	if (min < max)
		tab = ft_range_aux(min, max);
	else
		tab = 0;
	return (tab);
}
