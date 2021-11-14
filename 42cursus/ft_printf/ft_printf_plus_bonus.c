/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_plus_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 00:09:35 by rgallego          #+#    #+#             */
/*   Updated: 2021/11/14 17:45:22 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printf_plus(int nb)
{
	if (nb >= 0)
		return ((int)write(1, "+", 1) + ft_printf_int(nb));
	else
		return (ft_printf_int(nb));
}
