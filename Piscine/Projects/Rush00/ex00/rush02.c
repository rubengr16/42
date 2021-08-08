/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalabuc <mcalabuc@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 11:13:50 by mcalabuc          #+#    #+#             */
/*   Updated: 2021/08/07 13:10:52 by mcalabuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char c);

void	printsqr02(int i, int j, int x, int y)
{
	if (j == 0)
	{
		if (i == 0 || i == x - 1)
			ft_putchar('A');
		else
			ft_putchar('B');
	}
	else
	{
		if (j == y - 1)
		{
			if (i == 0 || i == x - 1)
				ft_putchar('C');
			else
				ft_putchar('B');
		}
		else
		{
			if (i == 0 || i == x - 1)
				ft_putchar('B');
			else
				ft_putchar(' ');
		}
	}
}

void	rush02(int x, int y)
{
	int	i;
	int	j;

	j = 0;
	while (j < y)
	{
		i = 0;
		while (i < x)
		{
			printsqr02(i, j, x, y);
			i++;
		}
		j++;
		ft_putchar('\n');
	}
}
