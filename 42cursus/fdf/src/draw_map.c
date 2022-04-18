/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:12:51 by rgallego          #+#    #+#             */
/*   Updated: 2022/04/18 14:06:41 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	bresen_x(t_img img, t_point start, t_point end, t_bresen bham)
{
	bham.variation = bham.d.y - (bham.d.x / 2);
	while (start.x != end.x)
	{
		start.x += bham.step.x;
		if (bham.variation >= 0)
		{
			start.y += bham.step.y;
			bham.variation -= bham.d.x;
		}
		bham.variation += bham.d.y;
		my_pixel_put(img, start.x, start.y, bham.colour);
	}
}

static void	bresen_y(t_img img, t_point start, t_point end, t_bresen bham)
{
	bham.variation = bham.d.x - (bham.d.y / 2);
	while (start.y != end.y)
	{
		start.y += bham.step.y;
		if (bham.variation >= 0)
		{
			start.x += bham.step.x;
			bham.variation -= bham.d.y;
		}
		bham.variation += bham.d.x;
		my_pixel_put(img, start.x, start.y, bham.colour);
	}
}

static void	bresenham(t_img img, t_point start, t_point end, int colour)
{
	t_bresen	bham;

	bham.colour = colour;
	bham.d.x = 2 * (ft_max(start.x, end.x) - ft_min(start.x, end.x));
	bham.d.y = 2 * (ft_max(start.y, end.y) - ft_min(start.y, end.y));
	bham.step = (t_point){1, 1};
	if ((end.x - start.x) < 0)
		bham.step.x = -1;
	if ((end.y - start.y) < 0)
		bham.step.y = -1;
	my_pixel_put(img, start.x, start.y, colour);
	if (bham.d.x > bham.d.y)
		bresen_x(img, start, end, bham);
	else
		bresen_y(img, start, end, bham);
}

static void	triple_print(t_fdf fdf, int i, int j)
{
	int	colour;

	colour = fdf.map.matrix[i][j].colour;
	if (j > 0)
		bresenham(fdf.img, get_pt(j - 1, i, fdf), get_pt(j, i, fdf), colour);
	if (i > 0)
		bresenham(fdf.img, get_pt(j, i - 1, fdf), get_pt(j, i, fdf), colour);
	if (i > 0 && j > 0)
		bresenham(fdf.img, get_pt(j - 1, i - 1, fdf), get_pt(j, i, fdf), \
				colour);
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
			triple_print(fdf, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(fdf.mlx, fdf.win, fdf.img.img, 0, 0);
}
