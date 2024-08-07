/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:36:04 by rgallego          #+#    #+#             */
/*   Updated: 2024/08/01 08:53:59 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversor(char c, va_list arg_list)
{
	if (c == 'c')
		return (ft_printf_chr(va_arg(arg_list, int)));
	else if (c == 's')
		return (ft_printf_str(va_arg(arg_list, char *)));
	else if (c == 'p')
		return (ft_printf_ptr(va_arg(arg_list, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_printf_int(va_arg(arg_list, int)));
	else if (c == 'u')
		return (ft_printf_uns(va_arg(arg_list, unsigned int)));
	else if (c == 'x')
		return (ft_printf_hex(va_arg(arg_list, unsigned int)));
	else if (c == 'X')
		return (ft_printf_hexup(va_arg(arg_list, unsigned int)));
	else
		return ((int)write(1, &c, 1));
}
#include <stdio.h>
int	ft_printf(const char *format, ...)
{
	va_list	arg_list;
	int		cnt;
	int		n_char;

	va_start(arg_list, format);
	cnt = 0;
	n_char = 0;
	while (format[cnt])
	{
		if (format[cnt] == '%')
		{
			if (format[cnt + 1])
			{
				cnt++;
				n_char += ft_conversor(format[cnt], arg_list);
			}
		}
		else
			n_char += write(1, &format[cnt], 1);
		cnt++;
	}
	va_end(arg_list);
	return (n_char);
}
