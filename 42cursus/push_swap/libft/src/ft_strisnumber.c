/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisnumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:00:14 by rgallego          #+#    #+#             */
/*   Updated: 2022/08/22 19:22:12 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * decides if a string represents one or more numbers.
 * INPUT:	char *str
 * OUTPUT:	int	:	1	numerical
 *					0	non numerical
 */
int	ft_strisnumber(char *str)
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
