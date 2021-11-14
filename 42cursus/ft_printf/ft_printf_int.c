/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:27:04 by rgallego          #+#    #+#             */
/*   Updated: 2021/11/14 17:44:13 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_int(int nb)
{
	long long	aux;
	int			n_char;

	if (nb < 0)
	{
		n_char = (int)write(1, "-", 1);
		aux = (long long)nb * -1;
	}
	else
	{
		n_char = 0;
		aux = nb;
	}
	return (n_char + ft_putnbr_base(aux, "0123456789", 10));
}
