/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_minus_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 12:41:41 by rgallego          #+#    #+#             */
/*   Updated: 2021/11/01 13:03:50 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int	ft_printf_minus(char *str, va_list arg_list, int *cnt)
{
	int	n_width;
	int	n_char;

	n_width = ft_width(str, cnt);
	n_char = ft_conversor(str[*cnt], arg_list);
	while (n_char < n_width)
	{
		write(1, " ", 1);
		n_char++;
	}
	return (n_char);
}
