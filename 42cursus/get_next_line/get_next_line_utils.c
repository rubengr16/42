/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:05:45 by rgallego          #+#    #+#             */
/*   Updated: 2021/10/14 15:34:20 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	search_nl(char *buffer, int *pos_nl, int n_char)
{
	*pos_nl = 0;
	while (*pos_nl < n_char && buffer[*pos_nl] != '\n')
		(*pos_nl)++;
}

void	insert_line(char **line, char *buffer, int *pos_nl, int *len)
{
	char	*aux;
	int		cnt;

	aux = *line;
	cnt = 0;
	*line = malloc(sizeof(char) * (*len + *pos_nl + 2));
	if (*line)
	{
		while (aux && aux[cnt] && cnt < *len)
		{
			(*line)[cnt] = aux[cnt];
			cnt++;
		}
		cnt = 0;
		while (cnt <= *pos_nl)
		{
			(*line)[*len] = buffer[cnt],
			cnt++;
			(*len)++;
		}
		if (*pos_nl != BUFFER_SIZE) //revisar
			(*line)[*len] = '\0';
		free(aux);	   
	}
	else
		*pos_nl = -1;
}

void	fill_rest(char **rest, char *buffer, int pos_nl)
{
	int	cnt;

	pos_nl++;
	if (buffer[pos_nl])
	{
		*rest = malloc(sizeof(char) * (BUFFER_SIZE - pos_nl));
		if (*rest)
		{
			cnt = 0;
			while (buffer[pos_nl] && pos_nl < BUFFER_SIZE)
			{
				(*rest)[cnt] = buffer[pos_nl];
				cnt++;
				pos_nl++;
			}
			(*rest)[cnt] = '\0';
		}
	}
	else 
		*rest = NULL;
}

void	read_line(char **rest, char **line, int len, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int		n_char;
	int		pos_nl;

	n_char = BUFFER_SIZE;
	pos_nl = BUFFER_SIZE;
	while (n_char == BUFFER_SIZE && pos_nl == BUFFER_SIZE)
	{
		n_char = read(fd, buffer, BUFFER_SIZE);
		if (n_char > 0)
		{		
			buffer[n_char] = '\0';
			search_nl(buffer, &pos_nl, n_char);
			insert_line(line, buffer, &pos_nl, &len);
		}
	}
	if (n_char == -1 || pos_nl == -1)
	{
		free(*line);
		line = NULL;
	}
	else if ((pos_nl - 1) != n_char)
		fill_rest(rest, buffer, pos_nl);	
}
