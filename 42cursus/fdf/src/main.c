/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:59:49 by rgallego          #+#    #+#             */
/*   Updated: 2022/04/06 18:47:01 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	leaks(void)
{
	system("leaks fdf");
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;
	int		fdin;

	fdf = (t_fdf){{NULL, NULL, {NULL, NULL, -1, -1, -1}}, \
		{-1, 0, 5, X0, Y0, NULL}};
	atexit(leaks);
	if (argc != 2)
		error_msg("Please, enter 2 arguments", ERR_USR);
	if (ft_strncmp(&argv[FILE][ft_strlen(argv[FILE]) - 4], ".fdf", 4))
		error_msg("Please, remember: <name>.fdf", ERR_USR);
	fdin = open(argv[FILE], O_RDONLY);
	if (fdin < 0)
		error_msg("File issues", ERR_SYS);
	read_matrix(&fdf.map, fdin);
	ft_mlx_init(&fdf.mlx);
	draw(&fdf);
	ft_free_matrix(fdf.map.matrix);
	mlx_loop(fdf.mlx.mlx);
	return (0);
}
