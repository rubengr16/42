/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 11:42:52 by rgallego          #+#    #+#             */
/*   Updated: 2021/11/01 11:46:00 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int ft_strlen(char *str)
{
	int	cnt;

	cnt = 0;
	if (str)
		while (str[cnt])
			cnt++;
	return (cnt);
}

int	ft_strchr(char *str, char c)
{
	int	cnt;

	cnt = 0;
	while (str[cnt] && str[cnt] != c)
		cnt++;
	return(str[cnt]);
}
