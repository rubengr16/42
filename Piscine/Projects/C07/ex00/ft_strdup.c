/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 11:51:01 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/20 12:46:35 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char	*str)
{
	int	len;

	len = 0;
	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}

char	*ft_strcpy(char *dest, char *src)
{
	char	*aux;

	aux = dest;
	while (*src)
	{
		*aux = *src;
		aux++;
		src++;
	}
	*aux = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*cpy;

	cpy =(char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (cpy)
		cpy = ft_strcpy(cpy, src);
	return (cpy);
}
