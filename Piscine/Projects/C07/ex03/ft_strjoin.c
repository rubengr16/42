/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 01:12:35 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/24 09:02:48 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_strslen(int size, char **strs)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		i++;
	}
	return (len);
}

char	*ft_strcpy(char *dest, char *src)
{
	while (*src)
	{
		*dest = *src;
		src++;
		dest++;
	}
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	char	*aux;
	int		i;

	if (size)
	{
		result = malloc(sizeof(char) * (ft_strslen(size, strs)
					+ ((size - 1) * ft_strlen(sep)) + 1));
		if (result)
		{
			aux = result;
			i = 0;
			while (i < size)
			{
				aux = ft_strcpy(aux, strs[i]);
				i++;
				if (i < size)
					aux = ft_strcpy(aux, sep);
			}
			*aux = '\0';
		}
	}
	else
		result = NULL;
	return (result);
}
