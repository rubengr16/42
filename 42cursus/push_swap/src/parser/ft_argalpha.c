/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argalpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>       +#+  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:53:55 by rgallego          #+#    #+#             */
/*   Updated: 2021/12/03 20:36:05 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
	
/*
 * function which decides if a string is only numerical
 * INPUT:	char *str
 * OUTPUT:	int	:	1	numerical
 *					0	non numerical
 */
int ft_strisdigit(char  *str)
{
	int	cnt;

	if (str)
	{
		cnt = 0;
		while (str[cnt] && ft_isdigit(str[cnt]))
			cnt++;
		if (!str[cnt])
			return (1);
	}
	return (0);
}
