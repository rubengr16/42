/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 11:21:25 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/06 13:00:13 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	boom(int *nb)
{
	write(1, "21",1);
	nb /= 100000000;
}

int	reverse(int nb)
{
	int	tmp;

	tmp = 0;
	while (nb != 0)
	{
		tmp = tmp * 10 + nb % 10;
		nb /= 10;
	}
	return (tmp);
}

void	ft_putnbr(int nb)
{
	char	aux;
	int		tmp;
	int		neg;

	neg = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		if (nb == -2147483648)
			boom(&nb);
		nb *= -1;
	}
	if (nb == 0)
		write(1, "0", 1);
	tmp = reverse(nb);
	while (tmp != 0)
	{
		aux = tmp % 10 + '0';
		tmp /= 10;
		write(1, &aux, 1);
	}
}

int	main(void)
{
	ft_putnbr(-2147483648);
	write(1, "\n", 1);
	ft_putnbr(928);
	write(1, "\n", 1);
	ft_putnbr(0);
	write(1, "\n", 1);
	ft_putnbr(217483647);
}
