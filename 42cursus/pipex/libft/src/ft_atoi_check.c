/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:24:28 by rgallego          #+#    #+#             */
/*   Updated: 2022/03/07 13:44:00 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * function which decides if the number represented by the string is inside the
 * range values of int
 * INPUT:	int nb, char *str
 * OUTPUT:	int	:	1	number cannot be represented 
 * 					0	number is correct
 */
int	ft_atoi_check(int nb, char *str)
{
	if ((!nb || nb == -1) && (ft_strlen(str) > 2))
		return (1);
	else
		return (0);
}
