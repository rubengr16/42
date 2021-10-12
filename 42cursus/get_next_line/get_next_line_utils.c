/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:05:45 by rgallego          #+#    #+#             */
/*   Updated: 2021/10/12 22:18:07 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	search_nl(char *buffer, int *pos_nl, int n_char)
{
	*pos_nl = 0;
	while (*pos_nl < n_char && buffer[*pos_nl] != '\n')
		(*pos_nl)++;
}

void	insert_line(char **line, char *buffer, int *len, int *pos_nl)
{
	char	*aux;
	int		cnt;

	aux = *line;
	cnt = 0;
	*line = malloc(sizeof(char) * (*len + *pos_nl + 2));
	if (*line)
	{
		while (cnt < *len)
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
		(*line)[*len] = '\0';
		//if(aux)
	   	//	free(aux);	   
	}
	else
		*pos_nl = -1;
}

void	fill_rest(char **rest, char *buffer, int pos_nl)
{
	int	cnt;
	
	*rest = malloc(sizeof(char) * (BUFFER_SIZE - pos_nl));
	if (*rest)
	{
		cnt = 0;
		pos_nl++;
		while (pos_nl < BUFFER_SIZE)
		{
			(*rest)[cnt] = buffer[pos_nl];
			cnt++;
			pos_nl++;
		}
		(*rest)[cnt] = '\0';
	}
}

void	read_line(char **rest, char **line, int len, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int		n_char;
	int		pos_nl;

	n_char = read(fd, buffer, BUFFER_SIZE);
	buffer[n_char] = '\0';
	search_nl(buffer, &pos_nl, n_char);
	insert_line(line, buffer, &pos_nl, &len);
	while (n_char == BUFFER_SIZE && pos_nl == BUFFER_SIZE)
	{
		n_char = read(fd, buffer, BUFFER_SIZE);
		buffer[n_char] = '\0';
		search_nl(buffer, &pos_nl, n_char);
		insert_line(line, buffer, &pos_nl, &len);
	}
	if (n_char == -1 || pos_nl == -1)
	{
		//if(*line)
		//	free(*line);
		//line = NULL;
	}
	else if ((pos_nl - 1) != n_char)
		fill_rest(rest, buffer, pos_nl);
}
