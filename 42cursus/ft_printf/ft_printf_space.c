/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 11:26:45 by rgallego          #+#    #+#             */
/*   Updated: 2021/11/01 12:19:12 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int	ft_printf_space_int(int nb)
{
	if (nb >= 0)
		return (write(1, " ", 1) + ft_printf_int(nb));
	else
		return (ft_printf_int(nb));
}

int	ft_printf_space_str(char *format, char *str, int *cnt)
{
	int	n_space;
	int	n_char;

	n_space = ft_width(format, cnt);
	n_char = 0;
	if (format[*cnt] == 's')
	{
		if (n_space)
		{
			n_space -= ft_strlen(str);
			n_char = n_space;
			while (n_space)
			{
				write(1, " ", 1);
				n_space--;
			}
		}
		return (n_char + ft_printf_str(str));
	}
	return (n_char);
}
