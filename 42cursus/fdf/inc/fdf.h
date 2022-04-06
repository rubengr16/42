/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 20:30:51 by rgallego          #+#    #+#             */
/*   Updated: 2022/04/06 21:14:37 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/******************************** LIBRARIES ********************************* */
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include "libft.h"
# include "get_next_line.h"

/**************************** ERROR MANAGEMENT ****************************** */
# define ERR_SYS 0
# define ERR_USR 1

/******************************** CONSTANTS ********************************* */
# define FILE 1
# define WIN_X 1080
# define WIN_Y 720
# define X0 300
# define Y0 300
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
	int		zoom;
	int		x0;
	int		y0;
	t_cell	**matrix;
}	t_map;

typedef struct s_img
{
	void	*img;
	void	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_fdf
{
	void		*mlx;
	void		*mlx_win;
	t_img		img;
	t_map		map;
}	t_fdf;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

/********************************** UTILS *********************************** */
void	ft_free_matrix(t_cell **matrix);
void	error_msg(char *str, int error);
int		count_elems(char **set);
t_point	get_pt(int x, int y, t_fdf fdf);

/********************************** PARSER ********************************** */
void	read_matrix(t_map *map, int fdin);

/******************************** MLX_MNGMENT ******************************* */
void	ft_mlx_init(void **mlx, void **mlx_win, t_img *img);
void	my_pixel_put(t_img img, int x, int y, int colour);

void	draw(t_fdf fdf);

#endif
