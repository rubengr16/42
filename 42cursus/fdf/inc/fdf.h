/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 20:30:51 by rgallego          #+#    #+#             */
/*   Updated: 2022/02/23 18:54:04 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/******************************** LIBRARIES ********************************* */
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include "libft.h"
# include "get_next_line.h"

/******************************** CONSTANTS ********************************* */
# define FILE 1
# define WHITE 0x00FFFFFF

/******************************** STRUCTURE ********************************* */
typedef struct s_cell
{
	int	z;
	int	colour;
}	t_cell;

typedef struct s_map
{
	int		size_x;
	int		size_y;
	t_cell	**matrix;
}	t_map;

/********************************** UTILS *********************************** */
void	error_msg(char *str);
int		count_elems(char **set);

/********************************** PARSER ********************************** */
void	read_matrix(t_map *map, int	fdin);

#endif
