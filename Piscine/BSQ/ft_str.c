/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrazale <lbrazale@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:57:39 by lbrazale          #+#    #+#             */
/*   Updated: 2021/08/26 14:27:40 by lbrazale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "struct.h"

int	is_diff(t_map *map, char *file)
{
	map->empty = *file;
	map->obstacle = *(file + 1);
	map->full = *(file + 2);
	if (*(file + 3) != '\n')
		return (0);
	if (map->empty == map->full || map->empty == map->obstacle
		|| map->obstacle == map->full)
		return (0);
	while (*file)
	{
		if (*file != map->full && *file != map->empty
			&& *file != map->obstacle && *file != '\n')
			return (0);
		file++;
	}
	return (1);
}

void	ft_print_error(void)
{
	char	*s;

	s = "map error\n";
	while (*s)
	{
		ft_putchar(*s);
		s++;
	}
}

char	*ft_atoi(char *str, int *nb)
{
	int	cnt;

	cnt = 0;
	*nb = 0;
	if ('0' <= str[cnt] && str[cnt] <= '9')
	{
		while ((str[cnt] >= '0' && str[cnt] <= '9') && nb >= 0)
		{
			*nb = *nb * 10 + str[cnt] - '0';
			cnt++;
		}
	}
	else
		*nb = -1;
	return (&(str[cnt]));
}
