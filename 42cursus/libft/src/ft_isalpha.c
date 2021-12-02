/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalpha.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 13:05:36 by rgallego          #+#    #+#             */
/*   Updated: 2021/09/13 13:52:23 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_isalpha(int c)
{
	int	alpha;

	alpha = 0;
	if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
		alpha = 1;
	return (alpha);
}