/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalabuc <mcalabuc@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 11:13:50 by mcalabuc          #+#    #+#             */
/*   Updated: 2021/08/08 16:45:58 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	printsqr(int col, int row, int x, int y)
{
	if ((col == 0 && row == 0 ) || ((col == x - 1 && row == y - 1)
			&& (y > 1 && x > 1)))
		ft_putchar ('/');
	else
	{
		if ((col == 0 && row == y - 1) || (col == x - 1 && row == 0))
			ft_putchar ('\\');
		else
		{
			if (col == 0 || row == 0 || col == x - 1 || row == y - 1)
				ft_putchar('*');
			else
				ft_putchar(' ');
		}
	}
}

void	rush(int x, int y)
{
	int	col;
	int	row;

	row = 0;
	while (row < y)
	{
		col = 0;
		while (col < x)
		{
			printsqr(col, row, x, y);
			col++;
		}
		row++;
		ft_putchar('\n');
	}
}
