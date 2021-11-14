/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:20:20 by rgallego          #+#    #+#             */
/*   Updated: 2021/11/14 17:48:37 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_str(char *s)
{
	int	cnt;

	if (s)
	{
		cnt = 0;
		while (s[cnt])
			cnt += (int)write(1, &s[cnt], 1);
		return (cnt);
	}
	else
		return ((int)write(1, "(null)", 6));
}
