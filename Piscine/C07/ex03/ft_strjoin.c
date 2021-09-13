/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 01:12:35 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/25 09:51:20 by rgallego         ###   ########.fr       */
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

int	ft_strcpy(char *dest, char *src, int	cnt)
{
	while (*src)
	{
		dest[cnt] = *src;
		cnt++;
		src++;
	}
	return (cnt);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		cnt;
	int		i;

	cnt = 0;
	if (size)
	{
		result = malloc(sizeof(char) * (ft_strslen(size, strs)
					+ ((size - 1) * ft_strlen(sep)) + 1));
		if (result)
		{
			i = 0;
			while (i < size)
			{
				cnt = ft_strcpy(result, strs[i], cnt);
				i++;
				if (i < size)
					cnt = ft_strcpy(result, sep, cnt);
			}
		}
	}
	else
		result = malloc(sizeof(char));
	result[cnt] = '\0';
	return (result);
}
