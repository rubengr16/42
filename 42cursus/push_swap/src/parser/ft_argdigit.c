/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:53:55 by rgallego          #+#    #+#             */
/*   Updated: 2022/02/23 20:11:59 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
 * function which decides if a string is only numerical
 * INPUT:	char *str
 * OUTPUT:	int	:	1	numerical
 *					0	non numerical
 */
static int	ft_strisdigit(char *str)
{
	int	cnt;

	if (str)
	{
		cnt = 0;
		while (str[cnt] && (ft_isdigit(str[cnt]) || str[cnt] == ' '))
			cnt++;
		if (!str[cnt])
			return (1);
	}
	return (0);
}

/*
 * function which decides if a set of strings is only numerical
 * INPUT:	char **set
 * OUTPUT:	int	:	1	numerical
 *					0	non numerical
 */
int	ft_setisdigit(char **set)
{
	int	cnt;

	if (set)
	{
		cnt = 0;
		while (set[cnt] && ft_strisdigit(set[cnt]))
			cnt++;
		if (!set[cnt])
			return (1);
	}
	return (0);
}
