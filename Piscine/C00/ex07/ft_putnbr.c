/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 11:21:25 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/09 17:12:51 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_aux(int nb)
{
	char	c;

	if (nb > 0)
	{
		c = nb % 10 + '0';
		ft_putnbr_aux(nb / 10);
		write(1, &c, 1);
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 12);
	else
	{
		if (nb == 0)
			write(1, "0", 1);
		else
		{
			if (nb < 0)
			{
				nb *= -1;
				write(1, "-", 1);
			}
			ft_putnbr_aux(nb);
		}	
	}
}
