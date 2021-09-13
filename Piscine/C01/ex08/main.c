/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 16:39:30 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/09 16:51:50 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size);

int	main(void)
{
	int num[4];
	int	cont;

	num[0] = 4;
	num[1] = 1;
	num[2] = 3;
	num[3] = 2;
	cont = 0;
	while (cont < 4)
	{
		printf("%d\n", num[cont]);
		cont++;
	}
	ft_sort_int_tab(num, 4);
	cont = 0;
	while (cont < 4)
	{
		printf("%d\n", num[cont]);
		cont++;
	} 

}
