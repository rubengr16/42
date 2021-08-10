/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 17:39:52 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/10 09:37:37 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	lvl_comb(char num[], int lvl, int size);


void	print_comb(char num[], int lvl, int size)
{
	if (lvl == (size - 1))
	{
		write(1, num, size);
		if (num[0] < ((10 - size) + '0'))
			write(1, ", ", 2);
	}
}


void	ft_comb_aux(char num[], int lvl, int size)
{
	if (lvl < size)
	{
		if (lvl == 0)
			lvl_comb(num, lvl + 1, size);
		else
		{
			num[lvl] = num[lvl - 1] + 1;
			lvl_comb(num, lvl + 1, size);
		}
	}
	else
		print_comb(num, lvl, size);
}

void	lvl_comb(char num[], int lvl, int size)
{
	while (num[lvl] < ((10 + lvl - size) + '0'))
	{
		num[lvl] = num[lvl] + 1;
		ft_comb_aux(num, lvl + 1, size);
	}
}


void	ft_print_combn(int n)
{
	char	num[10];

	num[0] = '/';
	ft_comb_aux(num, 0, n);
}
