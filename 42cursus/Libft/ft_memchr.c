/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 10:04:47 by rgallego          #+#    #+#             */
/*   Updated: 2021/09/14 11:42:16 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str_s;

	str_s = s;
	while (*str_s && *str_s != (unsigned char)c && n > 0)
	{
		str_s++;
		n--;
	}
	if (*str_s == (unsigned char)c && n > 0)
		return ((void *)str_s);
	else
		return (NULL);
}
