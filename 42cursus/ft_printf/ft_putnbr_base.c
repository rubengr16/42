/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 19:15:13 by rgallego          #+#    #+#             */
/*   Updated: 2021/11/14 17:50:16 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long long nb, char *base, int len_base)
{
	if (nb < (unsigned long long)len_base)
		return ((int)write(1, &base[nb], 1));
	else
		return (ft_putnbr_base(nb / len_base, base, len_base)
			+ (int)write(1, &base[nb % len_base], 1));
}
