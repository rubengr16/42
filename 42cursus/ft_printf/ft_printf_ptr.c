/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 20:11:17 by rgallego          #+#    #+#             */
/*   Updated: 2021/11/01 12:54:08 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf_ptr(void *ptr)
{
	return (write(1, "0x", 2) + ft_putnbr_base((unsigned long long)ptr,
			"0123456789abcdef", 16));
}
