/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:12:51 by rgallego          #+#    #+#             */
/*   Updated: 2022/03/18 20:32:30 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	bresenham(t_mlx_data mlx, t_point start_pt, t_point end_pt, int colour)
{
	int	dec;
	int	variation[2];

	dec = 2 * (start_pt.y - end_pt.y) - (start_pt.x - end_pt.x);
	variation[0] = 2 * (start_pt.y - end_pt.y);
	variation[1] = 2 * (start_pt.y - end_pt.y) - 2 * (start_pt.x - end_pt.x);
	my_pixel_put(&mlx.img, start_pt.x, start_pt.y, colour);
	while (start_pt.x < end_pt.x)
	{
		if (dec < 0)
			dec += variation[0];
		else
		{
			dec += variation[1];
			start_pt.y++;
		}
		start_pt.x++;
		my_pixel_put(&mlx.img, start_pt.x, start_pt.y, colour);
	}
}
static void	horizontal(t_mlx_data mlx, t_point start_pt, t_point end_pt, int colour)
{
	my_pixel_put(&mlx.img, start_pt.x, start_pt.y, colour);
	while (start_pt.x < end_pt.x)
	{
		start_pt.x++;
		my_pixel_put(&mlx.img, start_pt.x, start_pt.y, colour);
	}
}

static void	vertical(t_mlx_data mlx, t_point start_pt, t_point end_pt, int colour)
{
	my_pixel_put(&mlx.img, start_pt.x, start_pt.y, colour);
	while (start_pt.y < end_pt.y)
	{
		start_pt.y++;
		my_pixel_put(&mlx.img, start_pt.x, start_pt.y, colour);
	}
}

void	draw(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf->map.y)
	{
		j = 0;
		while (j < fdf->map.x)
		{
			if (j > 0)
				horizontal(fdf->mlx, get_pt(j - 1, i, *fdf), get_pt(j, i, *fdf), fdf->map.matrix[i][j].colour);
			if (i > 0)
				vertical(fdf->mlx, get_pt(j, i - 1, *fdf), get_pt(j, i, *fdf), fdf->map.matrix[i][j].colour);
			if (i > 0 && j > 0)
				bresenham(fdf->mlx, get_pt(j - 1, i - 1, *fdf), get_pt(j, i, *fdf), fdf->map.matrix[i][j].colour);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(fdf->mlx.mlx, fdf->mlx.mlx_win, fdf->mlx.img.img, 0, 0);
}
