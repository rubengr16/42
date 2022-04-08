/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_mngment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:03:07 by rgallego          #+#    #+#             */
/*   Updated: 2022/04/08 19:36:37 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_mlx_init(void **mlx, void **win, t_img *img)
{
	*mlx = mlx_init();
	*win = mlx_new_window(*mlx, WIN_X, WIN_Y, "fdf");
	img->img = mlx_new_image(*mlx, WIN_X, WIN_Y);
	img->addr = mlx_get_data_addr(\
			img->img, &img->bpp, &img->line_len, &img->endian);
}

void	my_pixel_put(t_img img, int x, int y, int colour)
{
	char	*dst;

	if ((0 <= x && x < WIN_X) && (0 <= y && y < WIN_Y))
	{
		dst = img.addr + y * img.line_len + x * (img.bpp / 8);
		*(unsigned int *)dst = colour;
	}
}

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

int	event_mngment(int key_code, t_fdf *fdf)
{
	if (key_code == KEY_ESC)
	{
		mlx_destroy_window(fdf->mlx, fdf->win);
		exit(0);
	}
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
	else if (key_code == KEY_Z)
		fdf->map.zoom += 2;
	else if (key_code == KEY_X)
		if (fdf->map.zoom > ZOOM0)
			fdf->map.zoom -= 2;
	clear_window(fdf->img);
	draw(*fdf);
	return (0);
}
