/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 19:49:05 by rgallego          #+#    #+#             */
/*   Updated: 2022/04/17 16:03:16 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	clear_window(t_img img)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_Y)
	{
		j = 0;
		while (j < WIN_X)
		{
			my_pixel_put(img, j, i, BLACK);
			j++;
		}
		i++;
	}
}

static void	destroy(void *mlx, void *win)
{
	mlx_destroy_window(mlx, win);
	exit(0);
}

static void	zoom_mngment(t_fdf *fdf, int key_code)
{
	if (key_code == KEY_Z)
		fdf->map.zoom += fdf->map.zoom0;
	else if (key_code == KEY_X)
		if (fdf->map.zoom > fdf->map.zoom0)
			fdf->map.zoom -= fdf->map.zoom0;
}

static void	rotation_mngment(int key_code, t_fdf *fdf)
{	
	if (key_code == KEY_O)
		fdf->map.rot = ROT0;
	else if (key_code == KEY_R)
		fdf->map.rot += 0.05;
	else if (key_code == KEY_E)
		fdf->map.rot -= 0.05;
}

int	event_mngment(int key_code, t_fdf *fdf)
{
	if (key_code == KEY_ESC)
		destroy(fdf->mlx, fdf->win);
	else if (key_code == KEY_LEFT)
		fdf->map.x0 -= 5;
	else if (key_code == KEY_RIGHT)
		fdf->map.x0 += 5;
	else if (key_code == KEY_DOWN)
		fdf->map.y0 += 5;
	else if (key_code == KEY_UP)
		fdf->map.y0 -= 5;
	else if (key_code == KEY_U)
		fdf->map.height += 1;
	else if (key_code == KEY_I)
		fdf->map.height -= 1;
	else if (key_code == KEY_Z || key_code == KEY_X)
		zoom_mngment(fdf, key_code);
	else if (key_code == KEY_O || key_code == KEY_R || key_code == KEY_E)
		rotation_mngment(key_code, fdf);
	else if (key_code == KEY_P)
		fdf->map.perspective *= -1;
	clear_window(fdf->img);
	draw(*fdf);
	return (0);
}
