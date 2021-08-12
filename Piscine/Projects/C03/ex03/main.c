/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:01:33 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/11 17:22:51 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	cont_src;
	int	cont_dest;

	cont_src = 0;
	cont_dest = 0;
	while (dest[cont_dest] != '\0')
		cont_dest++;
	while (src[cont_src] != '\0')
	{
		dest[cont_dest] = src[cont_src];
		cont_src++;
		cont_dest++;
	}
	dest[cont_dest] = '\0';
	return (dest);
}
