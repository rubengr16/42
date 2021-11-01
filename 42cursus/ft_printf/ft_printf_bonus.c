/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:36:04 by rgallego          #+#    #+#             */
/*   Updated: 2021/11/01 12:58:36 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

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

int	ft_conversor_bonus(char *str, va_list arg_list, int *cnt)
{
	(*cnt)++;
	if (str[*cnt - 1] == '-')
		return (ft_printf_minus(str, arg_list, cnt));
	/*else if (str[*cnt - 1] == '0')
		return (ft_printf_zer(va_arg(arg_list, char *)));
	else if (str[*cnt - 1] == '.')
		return (ft_printf_point(va_arg(arg_list, void *)));*/
	else if (str[*cnt - 1] == '#' && (str[*cnt] == 'x' || str[*cnt] == 'X'))
		return (ft_printf_sharp(va_arg(arg_list, unsigned int), str[*cnt]));
	else if (str[*cnt - 1] == ' ' && (str[*cnt] == 'd' || str[*cnt] == 'i'))
		return (ft_printf_space_int(va_arg(arg_list, int)));
	else if (str[*cnt - 1] == ' ' && (str[*cnt] == 's'
			|| ('0' <= str[*cnt] && str[*cnt] <= '9')))
		return (ft_printf_space_str(str, va_arg(arg_list, char *), cnt));
	else if (str[*cnt - 1] == '+' && (str[*cnt] == 'd' || str[*cnt] == 'i'))
		return (ft_printf_plus(va_arg(arg_list, int)));
	else
		return (0);
}

int	ft_normal_bonus(char *str, va_list arg_list, int *cnt)
{
	if (ft_strchr("-0.# +", str[*cnt]))
		return (ft_conversor_bonus(str, arg_list, cnt));
	else
		return (ft_conversor(str[*cnt], arg_list));
}

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
			cnt++;
			n_char += ft_normal_bonus((char *)format, arg_list, &cnt);
		}
		else
			n_char += write(1, &format[cnt], 1);
		cnt++;
	}
	va_end(arg_list);
	return (n_char);
}
