/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 20:11:17 by rgallego          #+#    #+#             */
/*   Updated: 2021/10/22 20:41:29 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf_ptr(void *ptr)
{
	if (ptr)
		return ((long long)ft_putnbr_base(ptr, "0123456789abcdef", 16));
	else
		return (write(1, "(null)", 6);
}
