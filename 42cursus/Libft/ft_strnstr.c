/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:27:17 by rgallego          #+#    #+#             */
/*   Updated: 2021/09/17 16:11:37 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystac, const char *needle, size_t len)
{
	size_t	cnt;
	char *haystack = (char*)haystac;
	
	
	cnt = 0;	
	if (needle)
	{
		while (*haystack && len && cnt < len && needle[cnt])
		{
			cnt = 0;
			while (haystack[cnt] == needle[cnt] && needle[cnt])
				cnt++;
			haystack++;
			len--;
		}
		haystack--;
	}
	if ((!needle[cnt] && cnt < len))
		return ((char*)haystack);
	else
		return (NULL);
}
