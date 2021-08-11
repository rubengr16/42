/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 17:39:52 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/11 12:54:23 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb, int pow)
{
	char	c;

	if (nb / pow == 0)
	{
		write(1, "0", 1);
		if (pow != 1)
			ft_putnbr(nb % pow, pow / 10);
	}
	else
	{	
		if (nb > 0)
		{
			c = nb / pow + '0';
			write(1, &c, 1);
			if (pow != 1)
				ft_putnbr(nb % pow, pow / 10);
		}
	}
}

void	backtrak_combn(int num, int lvl, int n, int pow)
{
	if (lvl == (n - 1))
	{
		num = (num * 10) + (num % 10);
		while (((num + 1) % 10 > 0) && ((num % 10) < (11 + lvl - n)))
		{
			num++;
			ft_putnbr(num, pow);
			if ((num / pow) < (10 - n))
				write(1, ", ", 2);
		}
	}
	else
	{
		if (num == -1)
			num = 0;
		else
			num = (num * 10) + (num % 10 + 1);
		while (((num + 1) % 10 > 0) && ((num % 10) < (11 + lvl - n)))
		{
			backtrak_combn(num, lvl + 1, n, pow);
			num++;
		}
	}
}

int	ft_pow(int n)
{
	int	cont;
	int	num;

	cont = 0;
	num = 1;
	while (cont < (n - 1))
	{
		num *= 10;
		cont++;
	}
	return (num);
}

void	ft_print_combn(int n)
{
	if (0 < n && n < 10)
		backtrak_combn(-1, 0, n, ft_pow(n));
}
