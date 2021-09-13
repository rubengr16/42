/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puutnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 12:19:08 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/16 12:50:56 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

long	ft_pow(int nb)
{
	long	pow;

	pow = 1;
	while (nb / pow)
		pow *= 10;
	return (pow);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long			pow;
	unsigned int	nb_pos;

	pow = ft_pow(nb);
	if (nb < 0)
		ft_putchar('-');
	nb_pos = nb;
	if (nb_pos > 10)
	{
		while (pow > 1)
		{
			pow /= 10;
			ft_putchar((nb_pos / pow) + '0');
			nb_pos %= pow;
		}
	}
	else
		ft_putchar(nb_pos + '0');
}
