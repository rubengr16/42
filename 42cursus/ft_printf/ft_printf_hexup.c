/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 19:46:06 by rgallego          #+#    #+#             */
/*   Updated: 2021/10/22 20:24:04 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf_hexup(int nb)
{
	unsigned long long	aux;
	int					n_char;

	if (nb < 0)
	{
		n_char = write(1, "-", 1);
		aux = nb * -1;
	}
	else
	{
		n_char = 0;
		aux = nb;
	}
	return (n_char + ft_putnbr_base(aux, "0123456789ABCDEF", 16));
}
