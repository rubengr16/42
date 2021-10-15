/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:05:45 by rgallego          #+#    #+#             */
/*   Updated: 2021/10/15 17:38:33 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	search_nl(char *buffer, int *n_char)
{
	*n_char = 0;
	while (buffer[*n_char] && buffer[*n_char] != '\n')
		(*n_char)++;
	if (!buffer[*n_char] && *n_char < BUFFER_SIZE)
		(*n_char)--;
}

void	insert_line(char **line, char *buffer, int *n_char, int *len)
{
	char	*aux;
	int		cnt;

	aux = *line;
	*line = malloc(sizeof(char) * (*len + *n_char + 2));
	if (*line)
	{
		cnt = 0;
		while (cnt < *len && aux && aux[cnt])
		{
			(*line)[cnt] = aux[cnt];
			cnt++;
		}
		cnt = 0;
		while (cnt <= *n_char && cnt < BUFFER_SIZE)
		{
			(*line)[*len] = buffer[cnt];
			cnt++;
			(*len)++;
		}
		(*line)[*len] = '\0';
		free(aux);	   
	}
	else
		*n_char = -1;
}

void	fill_rest(char **rest, char *buffer, int n_char)
{
	int	cnt;

	n_char++;
	if (n_char < BUFFER_SIZE && buffer[n_char])
	{
		*rest = malloc(sizeof(char) * (BUFFER_SIZE - n_char));
		if (*rest)
		{
			cnt = 0;
			while (n_char < BUFFER_SIZE && buffer[n_char])
			{
				(*rest)[cnt] = buffer[n_char];
				cnt++;
				n_char++;
			}
		}
	}
}

void	read_line(char **rest, char **line, int len, int fd)
{
	char	*buffer;
	int		n_char;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	n_char = BUFFER_SIZE;
	if (buffer)
	{
		while (n_char == BUFFER_SIZE)
		{
			n_char = read(fd, buffer, BUFFER_SIZE);
			if (n_char > 0)
			{		
				buffer[n_char] = '\0';
				search_nl(buffer, &n_char);
				insert_line(line, buffer, &n_char, &len);
			}
		}
		if (n_char == -1)
			free(*line);
		else if (n_char > 0 && buffer[n_char + 1] != '\0')
			fill_rest(rest, buffer, n_char);
	}
	if (!buffer || n_char == -1)
		line = NULL;	
	free(buffer);
}
