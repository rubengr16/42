/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:56:30 by rgallego          #+#    #+#             */
/*   Updated: 2021/09/21 16:38:27 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_n_len(int n)
{
	int	len; 
		
	len = 0;
	if (n < 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int					len;
	unsigned long		aux;
	char				*n_str;

	len = ft_n_len(n);
	aux = (unsigned long)n;
	n_str = malloc(sizeof(char) * (len + 1));
	if (!n_str)
		return (NULL);
	n_str[len] = '\0';
	while (len && aux >= 10)
	{
		len--;
		n_str[len] = '0' + aux % 10;
		aux /= 10;
	}
	n_str[len] = '0' + aux % 10;
	if (len)
		n_str[0] = '-';
	return (n_str);
}
