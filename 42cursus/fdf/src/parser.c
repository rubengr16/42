/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 20:38:49 by rgallego          #+#    #+#             */
/*   Updated: 2022/03/02 18:36:20 by rgallego         ###   ########.fr       */
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
		value = ft_split(set[i], ',');
		if(!ft_isnumber(value[Z]))
			error_msg("Invalid map: z issues");
		line[j].z = ft_atoi(value[Z]);
		if ((!line[j].z || line[j].z != -1) && ft_len(value[Z] > 2))
			error_msg("Invalid map: z issues");
		if (value[COLOUR] && (ft_strcmp(value[COLOUR], "0x", 2) ||
			!ft_strisbase(&value[COLOUR][2], HEXUP_BASE)))
			error_msg("Invalid map: colour issues");
		if (value[COLOUR])
		{
			line[j].colour = ft_atoi_base(value[COLOUR]);
			if ((!line[j].colour || line[j].colour != -1) &&
				ft_len(value[COLOUR] > 2))
				error_msg("Invalid map: z issues");
		}
		else
			line[j].colour = 0x00FFFFFF;
		j++;
	}
}

static void	fill_matrix(t_map *map, char **set)
{
	t_cell	**aux;
	int		i;
	int		j;

	aux = map->matrix;
	map->matrix = malloc(sizeof(t_cell *) * (map->y + 1));
	if (!map->matrix)
		error_msg("Malloc failed");
	i = 0;
	while (i < (map->y - 1))
	{
		map->matrix[i] = aux[i];
		i++;
	}
	map->matrix[i] = malloc(sizeof(t_cell) * (map->x + 1));
	if (!map->matrix[i])
		error_msg("Malloc failed");
	ft_free_matrix(aux);
	fill_line(map->matrix[i], set);
}

void	read_matrix(t_map *map, int fdin)
{
	char	*line;
	char	**aux;

	line = get_next_line(fdin);
	while (line)
	{
		aux = ft_split(line, ' ');
		free(line);
		if (!aux)
			error_msg("Split failed");
		if (map->x)
			map->x = count_elems(aux);
		else if (map->x != count_elems(aux))
			error_msg("Invalid map: size issues");
		map->y++;
		fill_matrix_line(map, aux);
	}
}
