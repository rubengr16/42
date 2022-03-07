/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:59:49 by rgallego          #+#    #+#             */
/*   Updated: 2022/03/07 18:08:51 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	leaks(void)
{
	system("leaks fdf");
}

int	main(int argc, char **argv)
{
	t_map	map;
	int		fdin;

	map = (t_map){-1, 0, NULL};
	atexit(leaks);
	if (argc != 2)
		error_msg("Please, enter 2 arguments", ERR_USR);
	if (ft_strncmp(&argv[FILE][ft_strlen(argv[FILE]) - 4], ".fdf", 4))
		error_msg("Please, remember: <name>.fdf", ERR_USR);
	fdin = open(argv[FILE], O_RDONLY);
	if (fdin < 0)
		error_msg("File issues", ERR_SYS);
	read_matrix(&map, fdin);
	mlx_try();
	ft_free_matrix(map.matrix);
	return (0);
}
