/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 20:30:51 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/13 18:02:52 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/******************************** LIBRARIES ********************************* */
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include "mlx.h"
# include <math.h>
# include "keys.h"
# include "libft.h"
# include "get_next_line.h"

/**************************** ERROR MANAGEMENT ****************************** */
# define ERR_SYS 0
# define ERR_USR 1

/******************************** CONSTANTS ********************************* */
# define FILE 1
# define WIN_X 1080
# define WIN_Y 720
# define X0 200
# define Y0 200
# define ZOOM0 5
# define HEIGHT0 5
# define ROT0 0
# define ISOM 1
# define TOP -1
# define BASE "0123456789ABCDEF"
# define WHITE 0x00FFFFFF
# define BLACK 0x00000000
# define RAD 0.5
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
	int		height;
	int		x0;
	int		y0;
	int		zoom0;
	int		height0;
	int		perspective;
	float	rot;
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
	void		*win;
	t_img		img;
	t_map		map;
}	t_fdf;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_bresen
{
	int		colour;
	int		variation;
	t_point	step;
	t_point	d;
}	t_bresen;

/********************************** UTILS *********************************** */
void	error_msg(char *str, int error);
int		count_elems(char **set);
t_point	get_pt(int x, int y, t_fdf fdf);

/********************************** PARSER ********************************** */
void	read_matrix(t_map *map, int fdin);

/******************************** MLX_MNGMENT ******************************* */
void	ft_mlx_init(void **mlx, void **win, t_img *img);
void	my_pixel_put(t_img img, int x, int y, int colour);

/********************************** DRAW_MAP ******************************** */
void	draw(t_fdf fdf);

/******************************* EVENT_MNGMENT ****************************** */
int		event_mngment(int key_code, t_fdf *fdf);

#endif
