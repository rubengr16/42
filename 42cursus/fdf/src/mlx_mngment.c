/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_mngment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:03:07 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/13 19:26:14 by rgallego         ###   ########.fr       */
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
		printf("addr = %p, line len = %d, bpp - %d\n", img.addr, img.line_len, img.bpp);
		dst = img.addr + y * img.line_len + x * (img.bpp / 8);
		*(unsigned int *)dst = colour;
	}
}
