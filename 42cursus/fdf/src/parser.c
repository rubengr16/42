/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 20:38:49 by rgallego          #+#    #+#             */
/*   Updated: 2022/03/02 20:29:38 by rgallego         ###   ########.fr       */
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
		printf("\n%s", value[Z]);
		if(!ft_strisnumber(value[Z]))
			error_msg("Invalid map: z issues 1");
		line[j].z = ft_atoi(value[Z]);
		if ((!line[j].z || line[j].z != -1) && (ft_strlen(value[Z]) > 2))
			error_msg("Invalid map: z issues 2");
		if (value[COLOUR] && (ft_strncmp(value[COLOUR], "0x", 2) ||
			!ft_strisbase(&value[COLOUR][2], HEXUP_BASE)))
			error_msg("Invalid map: colour issues");
		if (value[COLOUR])
		{
			line[j].colour = ft_atoi_base(value[COLOUR], \
				HEXUP_BASE, ft_strlen(HEXUP_BASE));
			if ((!line[j].colour || line[j].colour != -1) &&
				(ft_strlen(value[COLOUR]) > 2))
				error_msg("Invalid map: colour issues");
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
	map->matrix[map->y] = NULL;
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
			error_msg("Split failed");
		if (map->x)
			map->x = count_elems(set);
		else if (map->x != count_elems(set))
			error_msg("Invalid map: size issues");
		map->y++;
		// REMIND free(set);
		fill_matrix(map, set);
		line = get_next_line(fdin);
	//	write(1, "hello", 5);
	}
}
