/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 12:17:10 by rgallego          #+#    #+#             */
/*   Updated: 2021/11/01 13:24:57 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int	ft_printf_width(char *str, va_list arg_list, int *cnt)
{
	int	n_space;
	int	n_char;

	n_space = ft_width(str, cnt);
	return (ft_width_conversor(str[*cnt], arg_list, cnt, n_space));	//think this
}

int ft_width(char *str, int *cnt)
{
	int	n_space;

	n_space = 0;
	while ('0' <= str[*cnt] && str[*cnt] <= '9')
	{
		n_space = (n_space * 10) + (str[*cnt] - '0');
		(*cnt)++;

	}
	return (n_space);
}
