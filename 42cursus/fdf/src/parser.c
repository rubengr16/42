/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 20:38:49 by rgallego          #+#    #+#             */
/*   Updated: 2022/03/09 16:20:58 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fill_line(t_cell *line, char **set)
{
	char	**value;
	int		j;

	j = 0;
	while (set[j])
	{
		value = ft_split(set[j], ',');
		if (!ft_strisnumber(value[Z]))
			error_msg("Invalid map: z is not a number", ERR_USR);
		line[j].z = ft_atoi(value[Z]);
		if (ft_atoi_check(line[j].z, value[Z]))
			error_msg("Invalid map: z is not int", ERR_USR);
		line[j].colour = WHITE;
		if (value[COLOUR] && (ft_strncmp(value[COLOUR], "0x", 2)
				|| !ft_strisbase(&value[COLOUR][2], BASE)))
			error_msg("Invalid map: colour is not hexup", ERR_USR);
		if (value[COLOUR])
		{
			line[j].colour = ft_atoi_base(value[COLOUR], BASE, ft_strlen(BASE));
			if (ft_atoi_check(line[j].colour, value[COLOUR]))
				error_msg("Invalid map: colour is not int", ERR_USR);
		}
		ft_free_split(value);
		j++;
	}
}

static void	fill_matrix(t_map *map, char **set)
{
	t_cell	**aux;
	int		i;

	aux = map->matrix;
	map->matrix = malloc(sizeof(t_cell *) * (map->y + 1));
	if (!map->matrix)
		error_msg("Malloc failed", ERR_SYS);
	i = 0;
	while (i < (map->y - 1))
	{
		map->matrix[i] = aux[i];
		i++;
	}
	map->matrix[i] = malloc(sizeof(t_cell) * (map->x));
	if (!map->matrix[i])
		error_msg("Malloc failed", ERR_SYS);
	free(aux);
	map->matrix[map->y] = NULL;
	fill_line(map->matrix[i], set);
}

void	read_matrix(t_map *map, int fdin)
{
	char	*line;
	char	*aux;
	char	**set;

	line = get_next_line(fdin);
	while (line)
	{
		aux = ft_strtrim(line, "\n");
		free(line);
		set = ft_split(aux, ' ');
		free(aux);
		if (!set)
			error_msg("Split failed", ERR_SYS);
		if (map->x < 0)
			map->x = count_elems(set);
		else if (map->x != count_elems(set))
			error_msg("Invalid map: size issues", ERR_USR);
		map->y++;
		fill_matrix(map, set);
		ft_free_split(set);
		line = get_next_line(fdin);
	}
}
