/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_mngment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:03:07 by rgallego          #+#    #+#             */
/*   Updated: 2022/04/06 20:59:25 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_mlx_init(void **mlx, void **mlx_win, t_img *img)
{
	*mlx = mlx_init();
	*mlx_win = mlx_new_window(*mlx, WIN_X, WIN_Y, "fdf");
	img->img = mlx_new_image(*mlx, WIN_X, WIN_Y);
	img->addr = mlx_get_data_addr(\
			img->img, &img->bpp, &img->line_len, &img->endian);
}

void	my_pixel_put(t_img *img, int x, int y, int colour)
{
	int		offset;
	char	*dst;

	if ((0 <= x && x < WIN_X) && (0 <= y && y < WIN_Y))
	{
		offset = y * img->line_len + x * (img->bpp / 8);
		dst = img->addr + offset;
		*(unsigned int *)dst = colour;
	}
}
