/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:01:33 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/16 10:14:19 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	cont_src;
	int	cont_dest;

	cont_src = 0;
	cont_dest = 0;
	while (dest[cont_dest])
		cont_dest++;
	while (src[cont_src] && cont_src < nb)
	{
		dest[cont_dest] = src[cont_src];
		cont_src++;
		cont_dest++;
	}
	dest[cont_dest] = '\0';
	return (dest);
}
