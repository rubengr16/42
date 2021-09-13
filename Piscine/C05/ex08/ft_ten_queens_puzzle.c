/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:45:31 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/19 10:17:47 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write_sol(int sol[10])
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = sol[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	ft_abs(int nb)
{
	if (nb < 0)
		nb *= 1;
	return (nb);
}

int	ft_is_sol(int sol[10])
{
	int	i;
	int	j;
	int	val_sol;

	i = 0;
	val_sol = 1;
	while (i < 10 && val_sol)
	{
		j = i + 1;
		while (j < 10 && val_sol)
		{
			if (ft_abs(i - sol[i]) == (ft_abs(j - sol[j]))
				|| ((i + sol[i]) == (j + sol[j])))
				val_sol = 0;
			j++;
		}
		i++;
	}
	return (val_sol);
}

void	ft_solve_ten_queens(int	sol[10], int row[10], int *num_sol, int lvl)
{
	int	cand;

	if (lvl == 10)
	{
		if (ft_is_sol(sol))
		{
			ft_write_sol(sol);
			(*num_sol)++;
		}
	}
	else
	{
		cand = 0;
		while (cand < 10)
		{
			sol[lvl] = cand;
			if (!row[cand])
			{
				row[cand] = 1;
				ft_solve_ten_queens(sol, row, num_sol, lvl + 1);
				row[cand] = 0;
			}
			cand++;
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	sol[10];
	int	row[10];
	int	num_sol;

	num_sol = 0;
	while (num_sol < 10)
	{
		row[num_sol] = 0;
		num_sol++;
	}
	num_sol = 0;
	ft_solve_ten_queens(sol, row, &num_sol, 0);
	return (num_sol);
}
