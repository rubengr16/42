/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 19:15:13 by rgallego          #+#    #+#             */
/*   Updated: 2021/10/25 20:56:20 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr_base(long long nb, char *base, int len_base)
{
	if (nb < (long long)len_base)
		return (write(1, &base[nb], 1));
	else
		return (ft_putnbr_base(nb / 10, base, len_base)
			+ write(1, &base[nb % 10], 1));
}
