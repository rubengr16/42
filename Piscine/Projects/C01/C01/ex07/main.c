/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 14:22:59 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/09 14:31:02 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size);

int	main(void)
{
	int	num[3] = {1, 2, 3};

	for (int i = 0; i < 3; i++)
		printf("%d\n", num[i]);
	ft_rev_int_tab(num, 3);
	for (int i = 0; i < 3; i++)
		printf("%d\n", num[i]);

}
