/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_sharp_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 10:51:57 by rgallego          #+#    #+#             */
/*   Updated: 2021/11/14 17:46:03 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printf_sharp(unsigned int nb, char c)
{
	if (!nb)
		return (ft_printf_hex(nb));
	else if (c == 'x')
		return ((int)write(1, "0x", 2) + ft_printf_hex(nb));
	else
		return ((int)write(1, "0X", 2) + ft_printf_hexup(nb));
}
