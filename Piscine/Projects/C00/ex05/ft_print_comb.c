/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 08:57:50 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/09 14:07:00 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*num_to_char(int num)
{
	char	*c;
	char	aux;

	aux = '\0';
	c = &aux;
	*c = num + '0';
	return (c);
}

void	ft_print_num(int num[])
{
	write(1, num_to_char(num[0]), 1);
	write(1, num_to_char(num[1]), 1);
	write(1, num_to_char(num[2]), 1);
	if (num[0] != 7 || num[1] != 8 || num[2] != 9)
		write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	int	num[3];

	num[0] = 0;
	write(1, "", 1);
	while (num[0] < 10)
	{
		num[1] = num[0] + 1;
		while (num[1] < 10)
		{
			num[2] = num[1] + 1;
			while (num[2] < 10)
			{
				ft_print_num(num);
				num[2]++;
			}
			num[1]++;
		}
		num[0]++;
	}
}	
