/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrazale <lbrazale@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 14:40:22 by lbrazale          #+#    #+#             */
/*   Updated: 2021/08/26 13:19:31 by lbrazale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <stdlib.h>

int	ft_pos_sol(t_map *map, int col, int row, int length)
{
	int	i;
	int	j;

	i = row;
	while ((i < map->y) && ((i - row) < length))
	{
		j = col;
		while ((j < (map->x - 1)) && ((j - col) < length))
		{
			if (map->map[i][j] == map->obstacle)
				return (0);
			j++;
		}
		i++;
	}
	if (((i - row) < length) || ((j - col) < length))
		return (0);
	return (1);
}

void	ft_solution(t_map *map, t_sol *sol, int col, int row)
{
	while (row < (map->y - sol->length))
	{
		col = 0;
		while ((col < (map->x - sol->length - 1)))
		{
			while (ft_pos_sol(map, col, row, sol->length + 1))
			{
				sol->i = row;
				sol->j = col;
				sol->length = sol->length + 1;
			}
			col++;
		}
		row++;
	}
}

void	ft_solve(t_map *map, t_sol *sol)
{
	ft_solution(map, sol, 0, 0);
}

void	ft_putsol(t_map *map, t_sol *sol)
{
	int	i;
	int	j;

	i = sol->i;
	if ((sol->length - 1) < 1)
		return ;
	while ((i - sol->i) != sol->length)
	{
		j = sol->j;
		while ((j - sol->j) != sol->length)
		{
			map->map[i][j] = map->full;
			j++;
		}
		i++;
	}
}
