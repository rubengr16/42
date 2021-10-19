/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:05:45 by rgallego          #+#    #+#             */
/*   Updated: 2021/10/19 15:31:51 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	old_line_cpy(char **line, char *aux)
{
	int cnt;

	cnt = 0;
	while (aux && aux[cnt])
	{
		(*line)[cnt] = aux[cnt];
		cnt++;
	}
}
	
void	new_line_cpy(char **line, char *buffer, int n_char, int *len)
{
	int	cnt;

	cnt = 0;
	while (cnt <= n_char && buffer[cnt])
	{
		(*line)[*len] = buffer[cnt];
		(*len)++;
		cnt++;
	}
	(*line)[*len] = '\0';
}

void	insert_line(char **line, char *buffer, int *n_char, int *len)
{
	char	*aux;

	*n_char = 0;
	aux = *line;
	while (buffer[*n_char] && buffer[*n_char] != '\n')
		(*n_char)++;
	if (!buffer[*n_char])
		*line = malloc(sizeof(char) * (*len + *n_char + 1));
	else
		*line = malloc(sizeof(char) * (*len + *n_char + 2));
	if (*line)
	{
		old_line_cpy(line, aux);
		new_line_cpy(line, buffer, *n_char, len);
	}
	else
		*n_char = -1;
	free(aux);
}

void	fill_rest(char **rest, char *buffer, int n_char)
{
	int	cnt;

	*rest = malloc(sizeof(char) * (BUFFER_SIZE - n_char));
	if (*rest)
	{
		cnt = 0;
		n_char++;
		while (buffer[n_char])
		{
			(*rest)[cnt] = buffer[n_char];
			cnt++;
			n_char++;
		}
		(*rest)[cnt] = '\0';
	}
}

void	read_line(char **rest, char **line, int len, int fd)
{
	char	*buffer;
	int		n_char;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer)
	{
		n_char = BUFFER_SIZE;
		while (n_char == BUFFER_SIZE)
		{
			n_char = read(fd, buffer, BUFFER_SIZE);
			if (n_char > 0)
			{		
				buffer[n_char] = '\0';
				insert_line(line, buffer, &n_char, &len);
			}
		}
		if (n_char == -1)
			free(*line);
		else if (buffer[n_char] == '\n' && buffer[n_char + 1])
			fill_rest(rest, buffer, n_char);
	}
	if (!buffer || n_char == -1)
		line = NULL;	
	free(buffer);
}
