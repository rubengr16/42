/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:09:31 by rgallego          #+#    #+#             */
/*   Updated: 2022/04/17 16:13:34 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	int		aux;
	float	ang;
	t_point	pt;

	ang = 0;
	pt.x = x * fdf.map.zoom;
	pt.y = y * fdf.map.zoom;
	aux = pt.x;
	if (fdf.map.perspective == TOP)
		ang = RAD;
	pt.x = (pt.x * cos(fdf.map.rot - ang)) + (pt.y * sin(fdf.map.rot - ang));
	pt.y = (aux * -sin(fdf.map.rot - ang)) + (pt.y * cos(fdf.map.rot - ang));
	if (fdf.map.perspective == ISOM)
	{
		pt.x = (pt.x - pt.y) * cos(RAD);
		pt.y = (pt.y + x * fdf.map.zoom) * sin(RAD) - \
			(fdf.map.matrix[y][x].z * fdf.map.height * \
			(fdf.map.zoom / fdf.map.zoom0));
	}
	pt.x += fdf.map.x0;
	pt.y += fdf.map.y0;
	return (pt);
}
