/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugonzal <jugonzal@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 12:55:06 by jugonzal          #+#    #+#             */
/*   Updated: 2021/08/22 14:41:21 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "struct.h"

int	ft_open(char *str)
{
	return (open(str, O_RDONLY));
}

int	ft_file_size(char *str)
{
	int		fdes;
	int		len;
	int		size;
	char	aux[255];

	fdes = ft_open(str);
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

char	*ft_read_file(char *str)
{	
	char	*file;
	int		len;
	int		fdes;

	fdes = ft_open(str);
	if (fdes > -1)
	{
		len = ft_file_size(str);
		if (len > -1)
		{
			file = malloc(sizeof(char) * (len + 1));
			if (file)
			{
				len = read(fdes, file, len);
				file[len] = '\0';
				if (fdes < -1)
					file = NULL;
			}
		}
		close(fdes);
	}
	if (fdes == -1 || len == -1)
		file = NULL;
	return (file);
}
