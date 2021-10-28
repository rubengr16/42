/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:27:04 by rgallego          #+#    #+#             */
/*   Updated: 2021/10/28 10:49:23 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf_int(int nb)
{
	long long	aux;
	int			n_char;

	if (nb < 0)
	{
		n_char = write(1, "-", 1);
		aux = (long long)nb * -1;
	}
	else
	{
		n_char = 0;
		aux = nb;
	}
	return (n_char + ft_putnbr_base(aux, "0123456789", 10));
}
