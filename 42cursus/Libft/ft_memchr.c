/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 10:04:47 by rgallego          #+#    #+#             */
/*   Updated: 2021/09/16 15:30:30 by rgallego         ###   ########.fr       */
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
	if (n > 0 && *str_s == (unsigned char)c)
		return ((void *)str_s);
	else
		return (NULL);
}
