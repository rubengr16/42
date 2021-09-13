/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 19:31:33 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/13 11:25:35 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int	cont;

	cont = 0;
	while (src[cont] && n > 0)
	{
		dest[cont] = src[cont];
		cont++;
		n--;
	}
	while (n > 0)
	{
		dest[cont] = '\0';
		cont++;
		n--;
	}
	return (dest);
}
