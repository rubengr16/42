/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 19:20:36 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/10 11:21:29 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcpy(char *dest, char *src)
{
	char	*aux_dest;
	char	*aux_src;

	aux_dest = dest;
	aux_src = src;
	while (*aux_src != '\0')
	{
		*aux_dest = *aux_src;
		aux_dest++;
		aux_src++;
	}
	*aux_dest = '\0';
	return (dest);
}
