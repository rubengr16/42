/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 20:30:51 by rgallego          #+#    #+#             */
/*   Updated: 2022/03/09 16:59:40 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/******************************** LIBRARIES ********************************* */
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <mlx.h>
# include "libft.h"
# include "get_next_line.h"

/**************************** ERROR MANAGEMENT ****************************** */
# define ERR_SYS 0
# define ERR_USR 1

/******************************** CONSTANTS ********************************* */
# define FILE 1
# define BASE "0123456789ABCDEF"
# define WHITE 0x00FFFFFF
# define Z 0
# define COLOUR	1

/******************************** STRUCTURE ********************************* */
typedef struct s_cell
{
	int	z;
	int	colour;
}	t_cell;

typedef struct s_map
{
	int		x;
	int		y;
	t_cell	**matrix;
}	t_map;

typedef struct s_data
{
	void	*img;
	void	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img_data;

/********************************** UTILS *********************************** */
void	ft_free_split(char **set);
void	ft_free_matrix(t_cell **matrix);
void	error_msg(char *str, int error);
int		count_elems(char **set);

/********************************** PARSER ********************************** */
void	read_matrix(t_map *map, int fdin);

/******************************** MLX_MNGMENT ******************************* */
void	mlx_try(void);
void	my_pixel_put(t_img_data *img, int x, int y, int colour);

#endif
