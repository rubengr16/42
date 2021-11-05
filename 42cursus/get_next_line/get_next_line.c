/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:02:13 by rgallego          #+#    #+#             */
/*   Updated: 2021/11/05 09:58:11 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{	
	static char	*rest = NULL;
	char		*line;
	int			len;
	int			pos_nl;
	int			tmp;

	if (fd >= 0 && BUFFER_SIZE > 0)
	{
		line = rest;
		rest = NULL;
		len = ft_strlen(line);
		if (ft_strchr_nl(line, &pos_nl) && line[pos_nl])
		{
			
		}
		else if (!line || pos_nl == len)
			read_line(&rest, &line, len, fd);
		return (line);
	}
	else
		return (NULL);
}
