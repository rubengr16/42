/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_mngment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:03:07 by rgallego          #+#    #+#             */
/*   Updated: 2022/03/16 20:34:09 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_mlx_init(t_mlx_data *mlx)
{
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, WIN_X, WIN_Y, "fdf");
	mlx->img.img = mlx_new_image(mlx->mlx, WIN_X, WIN_Y);
	mlx->img.addr = mlx_get_data_addr(\
			mlx->img.img, &mlx->img.bpp, &mlx->img.line_len, &mlx->img.endian);
}

void	mlx_try(t_mlx_data mlx)
{
	my_pixel_put(&mlx.img, WIN_X - 100, WIN_Y - 1, 0x00FF0000);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.img.img, 0, 0);
	mlx_loop(mlx.mlx);
}

void	my_pixel_put(t_img_data *img, int x, int y, int colour)
{
	int		offset;
	char	*dst;

	offset = y * img->line_len + x * (img->bpp / 8);
	if (0 <= offset && offset < (WIN_Y * img->line_len))
	{
		dst = img->addr + offset;
		*(unsigned int *)dst = colour;
	}
}
