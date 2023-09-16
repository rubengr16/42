/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:59:49 by rgallego          #+#    #+#             */
/*   Updated: 2023/09/16 23:47:36 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	fdf;
	int		fdin;

	fdf = (t_fdf){NULL, NULL, {NULL, NULL, -1, -1, -1}, \
		{-1, 0, ZOOM0, HEIGHT0, X0, Y0, ZOOM0, HEIGHT0, ISOM, ROT0, NULL}};
	if (argc != 2)
		error_msg("Please, enter 2 arguments", ERR_USR);
	if (ft_strncmp(&argv[FILE][ft_strlen(argv[FILE]) - 4], ".fdf", 4))
		error_msg("Please, remember: <name>.fdf", ERR_USR);
	fdin = open(argv[FILE], O_RDONLY);
	if (fdin < 0)
		error_msg("File issues", ERR_SYS);
	read_matrix(&fdf.map, fdin);
	ft_mlx_init(&fdf.mlx, &fdf.win, &fdf.img);
	draw(fdf);
	mlx_hook(fdf.win, ON_KEYDOWN, MASK, event_mngment, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
