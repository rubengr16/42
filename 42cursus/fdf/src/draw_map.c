/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:12:51 by rgallego          #+#    #+#             */
/*   Updated: 2022/04/06 19:03:29 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	bresenham(t_mlx_data mlx, t_point start, t_point end, int colour)
{
	int		variation;
	t_point	d;
	t_point	step;

	d.x = 2 * (ft_max(start.x, end.x) - ft_min(start.x, end.x));
	d.y = 2 * (ft_max(start.y, end.y) - ft_min(start.y, end.y));
	step = (t_point){1, 1};
	if ((end.x - start.x) < 0)
		step.x = -1;
	if ((end.y - start.y) < 0)
		step.y = -1;
	my_pixel_put(&mlx.img, start.x, start.y, colour);
	if (d.x > d.y)
	{
		variation = d.y - (d.x / 2);
		while (start.x != end.x)
		{
			start.x += step.x;
			if (variation >= 0)
			{
				start.y += step.y;
				variation -= d.x;
			}
			variation += d.y;
			my_pixel_put(&mlx.img, start.x, start.y, colour);
		}
	}
	else
	{
		variation = d.x - (d.y / 2);
		while (start.y != end.y)
		{
			if (variation >= 0)
			{
				start.x += step.x;
				variation -= d.y;
			}
			start.y += step.y;
			variation += d.x;
			my_pixel_put(&mlx.img, start.x, start.y, colour);
		}
	}
}

void	draw(t_fdf fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf.map.y)
	{
		j = 0;
		while (j < fdf.map.x)
		{
			if (j > 0)
				bresenham(fdf.mlx, get_pt(j - 1, i, fdf), get_pt(j, i, fdf), fdf.map.matrix[i][j].colour);
			if (i > 0)
				bresenham(fdf.mlx, get_pt(j, i - 1, fdf), get_pt(j, i, fdf), fdf.map.matrix[i][j].colour);
			if (i > 0 && j > 0)
				bresenham(fdf.mlx, get_pt(j - 1, i - 1, fdf), get_pt(j, i, fdf), fdf.map.matrix[i][j].colour);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(fdf.mlx.mlx, fdf.mlx.mlx_win, fdf.mlx.img.img, 0, 0);
}
