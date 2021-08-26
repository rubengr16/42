/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrazale <lbrazale@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 12:55:06 by jugonzal          #+#    #+#             */
/*   Updated: 2021/08/26 14:13:11 by lbrazale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "struct.h"

int	ft_file_size(char *str)
{
	int		fdes;
	int		len;
	int		size;
	char	aux[255];

	fdes = open(str, O_RDONLY);
	if (fdes > -1)
	{
		len = 0;
		size = 1;
		while (size)
		{
			size = read(fdes, aux, 255);
			len += size;
		}
		close(fdes);
	}
	else
		len = -1;
	return (len);
}

void	ft_read_stdin(void)
{
	char	c;
	int		fdes;

	c = '\0';
	fdes = open("map.txt", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND,
			S_IRWXU);
	if (fdes > -1)
	{
		while (read(0, &c, 1))
			write(fdes, &c, 1);
		close(fdes);
	}
	else
		exit(EXIT_FAILURE);
}

char	*ft_read_file(char *str)
{	
	char	*file;
	int		len;
	int		fdes;

	fdes = open(str, O_RDONLY);
	if (fdes > -1)
	{
		len = ft_file_size(str);
		if (len > -1)
		{
			file = malloc(sizeof(char) * (len + 1));
			if (file)
				len = read(fdes, file, len);
		}
		close(fdes);
	}
	if (fdes == -1 || len == -1)
		exit(EXIT_FAILURE);
	file[len] = '\0';
	return (file);
}
