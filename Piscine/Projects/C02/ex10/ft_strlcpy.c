/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:53:11 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/13 12:58:50 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char	*dest, char *src, unsigned int size)
{
	unsigned int		len;

	len = 0;
	while (src[len] && (len < size - 1))
	{
		dest[len] = src[len];
		len++;
	}
	dest[len] = '\0';
	while (src[len])
		len++;
	return (len);
}
