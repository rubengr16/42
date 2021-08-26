/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrazale <lbrazale@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:57:48 by lbrazale          #+#    #+#             */
/*   Updated: 2021/08/26 14:40:41 by lbrazale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "struct.h"

void	ft_solve_write(t_map *map, t_sol *sol)
{
	ft_solve(map, sol);
	ft_putsol(map, sol);
	ft_print_matrix(map);
}

void	ft_init_sol(t_sol *sol)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	sol->i = i;
	sol->j = j;
	sol->length = len;
}

void	ft_free(t_map *map, char *file)
{
	int	i;

	i = 0;
	while (i < map->y)
	{
		free((map->map)[i]);
		i++;
	}
	free(map->map);
	free(file);
}

void	ft_input(char **file)
{
	ft_read_stdin();
	ft_putchar('\n');
	*file = ft_read_file("map.txt");
}

int	main(int argc, char **argv)
{
	char	*file;
	t_map	map;
	t_sol	sol;
	int		cnt;

	ft_init_sol(&sol);
	cnt = 0;
	while (cnt++ < argc)
	{
		if (argc == 1)
			ft_input(&file);
		else
			file = ft_read_file(argv[cnt]);
		ft_set_map(file, &map);
		if (map.x > -1)
		{
			ft_solve_write(&map, &sol);
			ft_free(&map, file);
		}
		else
			ft_print_error();
		if (cnt < (argc - 1))
			ft_putchar('\n');
	}
	return (0);
}
