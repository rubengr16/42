/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:53:11 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/10 17:02:24 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char	*dest, char *src, unsigned int size)
{
	char				*aux_dest;
	unsigned int		len;

	aux_dest = dest;
	len = 0;
	while (src[len] != '\0' && (len < size - 1))
	{
		*aux_dest = src[len];
		aux_dest++;
		len++;
	}
	aux_dest[len] = '\0';
	if (src[len] != '\0')
		while (src[len] != '\0')
			len++;
	return (len);
}
