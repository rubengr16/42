/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:59:49 by rgallego          #+#    #+#             */
/*   Updated: 2022/02/23 21:06:11 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	int		fdin;
	t_map	map;

	map = (t_map){-1, 0, NULL};
	if (argc != 2)
		error_msg(NULL);
	if (ft_strncmp(&argv[FILE][ft_strlen(argv[FILE]) - 4], ".fdf", 4))
		error_msg(NULL);
	fdin = open(argv[FILE], O_RDONLY);
	if (fdin < 0)
		error_msg(argv[FILE]);
	read_matrix(&map, fdin);
	return (0);
}
