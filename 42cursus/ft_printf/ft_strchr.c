/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 00:36:28 by rgallego          #+#    #+#             */
/*   Updated: 2021/11/01 01:08:06 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int	ft_strchr(char *str, char c)
{
	int	cnt;

	cnt = 0;
	while (str[cnt] && str[cnt] != c)
		cnt++;
	return(str[cnt]);
}
