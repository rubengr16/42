/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:59:49 by rgallego          #+#    #+#             */
/*   Updated: 2022/03/07 12:05:20 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_matrix(t_map map)
{
	int i;
	int	j;

	i = 0;
	while (i < map.y)
	{
		j = 0;
		printf("\nRow %3d", i);
		while (j < map.x)
		{
			printf("\n%6d, %6d", map.matrix[i][j].z, map.matrix[i][j].colour);
			j++;
		}
		i++;
	}
}

void leaks()
{
	system("leaks fdf");
}

int	main(int argc, char **argv)
{
	int		fdin;
	t_map	map;

	map = (t_map){-1, 0, NULL};
	//atexit(leaks);
	if (argc != 2)
		error_msg(NULL);
	if (ft_strncmp(&argv[FILE][ft_strlen(argv[FILE]) - 4], ".fdf", 4))
		error_msg(NULL);
	fdin = open(argv[FILE], O_RDONLY);
	if (fdin < 0)
		error_msg(argv[FILE]);
	read_matrix(&map, fdin);
	print_matrix(map);
	ft_free_matrix(map.matrix);
	print_matrix(map);
	system("leaks fdf");
	return (0);
}
