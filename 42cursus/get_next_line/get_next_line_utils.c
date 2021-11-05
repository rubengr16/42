/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:05:45 by rgallego          #+#    #+#             */
/*   Updated: 2021/11/05 20:04:25 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr_nl(char *str, int *pos_nl)
{
	*pos_nl = 0;
	if (str)
	{
		while (str[*pos_nl] && str[*pos_nl] != '\n')
			(*pos_nl)++;
		if (str[*pos_nl] == '\n')
			return  (1);
		else
			return (0);
	}
	else
		return (0);
}

void	ft_strcpy(char *dest, char *src, int len)
{
	int	cnt;

	cnt = 0;
	if (src)
	{
		while (cnt < len && src[cnt])
		{
			dest[cnt] = src[cnt];
			cnt++;
		}
	}
}

int ft_strjoin(char **dest, char *src, int len1, int len2)
{
	char	*aux;

	aux = *dest;
	 if (len2 < 0 || src[len2] == '\n')
	 	len2++;
	*dest = malloc(sizeof(char) * (len1 + len2 + 1));
	if (*dest)
	{
		ft_strcpy(*dest, aux, len1);
		if (len2)
		{
			ft_strcpy((*dest) + len1, src, len2);
			free(aux);
		}
		(*dest)[len1 + len2] = '\0';
		return (len1 + len2);
	}
	else
		return (-1);
}

void	ft_free_resources(char **str)
{
	free(*str);
	*str = NULL;
}
