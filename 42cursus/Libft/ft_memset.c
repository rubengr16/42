/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:08:29 by rgallego          #+#    #+#             */
/*   Updated: 2021/09/13 16:16:35 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	size_t			cnt;
	unsigned char	*str_s;

	str_s = s;
	cnt = 0;
	while (cnt < len)
	{
		str_s[cnt] = c;
		cnt++;
	}
	return (s);
}
