/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrazale <lbrazale@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:57:58 by lbrazale          #+#    #+#             */
/*   Updated: 2021/08/26 14:20:29 by lbrazale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "struct.h"

int	ft_str(char *str)
{
	int	cnt;

	cnt = 0;
	while (str[cnt] && str[cnt] != '\n')
		cnt++;
	return (cnt);
}

void	ft_create_map(t_map *map)
{
	int		i;

	map->map = malloc(sizeof(char *) * map->y + 1);
	if (map->map)
	{
		i = 0;
		while (i < map->y && i != -1)
		{
			(map->map)[i] = malloc(sizeof(char) * map->x + 1);
			if (!(map->map)[i])
				i = -1;
			else
				i++;
		}
		if (i == -1)
			map->map = NULL;
	}
}

void	ft_fill_map(t_map *map, char *file)
{
	int	i;
	int	j;

	i = 0;
	while (i < (map->y))
	{
		j = 0;
		while (j < (map->x - 1))
		{
			map->map[i][j] = file[map->x * i + j];
			j++;
		}
		map->map[i][j] = '\0';
		i++;
	}
}

void	ft_print_matrix(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->y)
	{
		j = 0;
		while (j < (map->x - 1))
		{
			ft_putchar(map->map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	ft_set_map(char	*file, t_map *map)
{
	int	cnt;
	int	cmp;

	file = ft_atoi(file, &cmp);
	if (is_diff(map, file))
	{
		file = file + 4;
		map->x = ft_str(file) + 1;
		map->y = 1;
		cnt = map->x;
		while (file[cnt])
		{
			cnt = cnt + ft_str(&(file[cnt])) + 1;
			(map->y)++;
			if (cnt != (map->x * map->y))
				exit(EXIT_FAILURE);
		}
		if (map->y != cmp)
			exit(EXIT_FAILURE);
		ft_create_map(map);
		ft_fill_map(map, file);
	}
	else
		map->x = -1;
}
