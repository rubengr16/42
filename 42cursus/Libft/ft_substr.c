/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:12:13 by rgallego          #+#    #+#             */
/*   Updated: 2021/09/14 17:18:38 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	s_len;

	sub_s = malloc(sizeof(char) * (len + 1));
	if (s && sub_s)
	{
		s_len = ft_strlen(s);
		if (start < s_len)
			(void)ft_strlcpy(sub_s, &s[start], len + 1);
		return (sub_s);
	}
	else
		return (NULL);
}
