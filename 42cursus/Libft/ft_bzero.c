/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:29:43 by rgallego          #+#    #+#             */
/*   Updated: 2021/09/13 16:13:49 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t		cnt;
	char		*str_s;

	str_s = s;
	cnt = 0;
	while (cnt < n)
	{
		str_s[cnt] = 0;
		cnt++;
	}
}
