/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:02:13 by rgallego          #+#    #+#             */
/*   Updated: 2021/10/15 17:38:36 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{	
	static char	*rest = NULL;
	char		*line;
	int			len;

	if (fd >= 0 && BUFFER_SIZE > 0)
	{
		len = 0;
		if (rest)
		{
			line = rest;
			rest = NULL;
			while (line[len])
				len++;
		}
		else
			line = NULL;
		read_line(&rest, &line, len, fd);
		return (line);
	}
	else
		return (NULL);
}
