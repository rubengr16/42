/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:09:31 by rgallego          #+#    #+#             */
/*   Updated: 2022/03/18 20:32:25 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_matrix(t_cell **matrix)
{
	int	i;

	i = 0;
	if (matrix)
	{
		while (matrix[i])
		{
			free(matrix[i]);
			i++;
		}
		free(matrix);
	}
}

void	error_msg(char *str, int error)
{
	if (error == ERR_SYS)
		perror(str);
	else
		ft_putendl_fd(str, STDERR_FILENO);
	exit(errno);
}

int	count_elems(char **set)
{
	int	n_elem;

	if (!set)
		return (0);
	n_elem = 0;
	while (set[n_elem])
		n_elem++;
	return (n_elem);
}

t_point	get_pt(int x, int y, t_fdf fdf)
{
	t_point	pt;

	pt = (t_point){x * fdf.map.zoom, y * fdf.map.zoom};
	return (pt);
}
