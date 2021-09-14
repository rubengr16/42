/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:17:52 by rgallego          #+#    #+#             */
/*   Updated: 2021/09/13 18:10:44 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		cnt;
	char		*str_dst;
	const char	*str_src;

	cnt = 0;
	str_dst = dst;
	str_src = src;
	if (dst != src)
	{
		if (src < dst)
			while (*str_dst != str_src[cnt])
				cnt++;
		if (cnt < len)
			ft_memcpy(dst, src, len);
		else
		{
			ft_memcpy(&dst[cnt], dst, len - cnt);
			ft_memcpy(dst, src, cnt);
		}
	}
	return (dst);
}
