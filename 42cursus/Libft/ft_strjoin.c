/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 09:12:02 by rgallego          #+#    #+#             */
/*   Updated: 2021/09/16 10:29:57 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*s;
	char	*aux;

	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2) + 1;
		s = malloc(sizeof(char) * (len));
		if (s)
		{
			aux = s;
			(void)ft_strlcpy(aux, s1, len);
			(void)ft_strlcat(aux, s2, len);
		}
		return (s);
	}
	else
		return (NULL);
}
