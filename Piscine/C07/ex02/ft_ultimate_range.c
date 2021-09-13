/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 12:21:52 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/23 10:07:24 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range_aux(int **range, int min, int max)
{
	int	size;
	int	i;

	size = max - min;
	**range = (int)malloc(sizeof(int) * size);
	if (*range)
	{
		i = 0;
		while (i < size)
		{
			(*range)[i] = min;
			min++;
			i++;
		}
	}
	else
		size = -1;
	return (size);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;

	if (min < max)
		size = ft_ultimate_range_aux(range, min, max);
	else
	{
		size = 0;
		range = 0;
	}
	return (size);
}
