/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 12:54:05 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/21 01:04:54 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max);

int	main(void)
{
	int	*tab;
	int	size;
	int	i;

	size = ft_ultimate_range(&tab, 2, 7);
	i = 0;
	printf("size = %d\n", size);
	while (i < size)
	{
		printf("%d\n", tab[i]);
		i++;
	}
	return (0);
}
