/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setisnumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:24:16 by rgallego          #+#    #+#             */
/*   Updated: 2022/08/22 17:36:18 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * decides if a set is only numerical.
 * INPUT:	char *str
 * OUTPUT:	int	:	1	numerical
 *					0	non numerical
 */
int	ft_setisnumber(char *str)
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
