/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:02:13 by rgallego          #+#    #+#             */
/*   Updated: 2021/11/08 16:18:24 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{	
	static char	*rest = NULL;
	char		*line;
	int			len;
	int			pos_nl;

	if (fd >= 0 && BUFFER_SIZE > 0)
	{
		line = rest;
		rest = NULL;
		len = 0;
		if (line)
			while (line[len])
				len++;
		if (ft_strchr_nl(line, &pos_nl) && pos_nl < len && line[pos_nl + 1])
		{
			(void)ft_strjoin(&rest, &line[pos_nl + 1], 0, len - pos_nl - 1);
			(void)ft_strjoin(&line, line, 0, pos_nl);
		}
		else if (!line || pos_nl == len)
			read_line(&line, &rest, len, fd);
		return (line);
	}
	else
		return (NULL);
}
