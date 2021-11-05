/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:02:13 by rgallego          #+#    #+#             */
/*   Updated: 2021/11/05 13:08:54 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	read_line(char **line, char **rest, int len, int fd)
{
	char	*buffer;
	int		n_char;
	int		pos_nl;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer)
	{
		n_char = BUFFER_SIZE;
		pos_nl = BUFFER_SIZE;
		while (n_char == BUFFER_SIZE && pos_nl == BUFFER_SIZE)
		{
			n_char = read(fd, buffer, BUFFER_SIZE);
			if (n_char > 0)
			{
				buffer[n_char] = '\0';
				pos_nl = ft_strchr_nl(str, &pos_nl);
				ft_strjoin(
			}
		}
	}
}

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
		if (str)
			while (str[len])
				len++;
		if (ft_strchr_nl(line, &pos_nl) && pos_nl < len && line[pos_nl + 1])
		{
			(void)ft_strjoin(&rest, &line[pos_nl], len - pos_nl - 1, 0),
			(void)ft_strjoin(&line, line, 0, pos_nl);
		}
		else if (!line || pos_nl == len)
			read_line(&rest, &line, len, fd);
		return (line);
	}
	else
		return (NULL);
}
