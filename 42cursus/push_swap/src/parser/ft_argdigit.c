/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:53:55 by rgallego          #+#    #+#             */
/*   Updated: 2022/08/22 21:08:30 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
 * decides if a string is only numerical
 * INPUT:	char *str
 * OUTPUT:	int	:	1	numerical
 *					0	non numerical
 */
static int	strisdigit(char *str)
{
	int	cnt;

	if (!str)
		return (0);
	cnt = 0;
	while (str[cnt] && (ft_isdigit(str[cnt]) || str[cnt] == ' '
			|| (str[cnt] == '-' && ft_isdigit(str[cnt + 1]))))
		cnt++;
	if (str[cnt])
		return (0);
	return (1);
}

/*
 * decides if a set of strings is only numerical
 * INPUT:	char **set
 * OUTPUT:	int	:	1	numerical
 *					0	non numerical
 */
int	setisdigit(char **set)
{
	int	cnt;

	if (!set)
		return (0);
	cnt = 0;
	while (set[cnt] && ft_strisdigit(set[cnt]))
		cnt++;
	if (set[cnt])
		return (0);
	return (1);
}
