/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 20:38:49 by rgallego          #+#    #+#             */
/*   Updated: 2022/02/23 21:16:52 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fill_matrix_line(t_map *map, char **set)
{
	map->matrix = malloc(sizeof(t_cell *) * (map->y + 1));
	if (!map->matrix)
		error_msg("Malloc failed");
	map->matrix[map->y - 1] = malloc(sizeof(t_cell) * (map->x + 1));
	if (!map->matrix[map->y - 1])
		error_msg("Malloc failed");
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
			error_msg("Invalid map");
		map->y++;
		fill_matrix_line(map, aux);
	}
}
