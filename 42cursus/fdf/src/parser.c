/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 20:38:49 by rgallego          #+#    #+#             */
/*   Updated: 2022/02/23 19:05:19 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	read_matrix(t_map *map, int	fdin)
{
	char	*line;
	char	**aux;

	line = get_next_line(fdin);
	aux = ft_split(line, ' ');
	if (!aux)
		error_msg("Split failed");
	map->size_x = count_elems(aux);
	map->size_y = 1;
	
}
