/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 11:37:58 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/16 12:13:38 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	cont_dest;
	int				cont_src;

	cont_dest = 0;
	cont_src = 0;
	while (dest[cont_dest] && cont_dest < (size - 1))
		cont_dest++;
	while (src[cont_src] && cont_dest < (size - 1))
	{
		dest[cont_dest] = src[cont_src];
		cont_dest++;
		cont_src++;
	}
	dest[cont_dest] = '\0';
	if ((size - 1) == cont_dest)
	{
		while (src[cont_src])
		{
			cont_dest++;
			cont_src++;
		}
	}
	return (cont_dest);
}
