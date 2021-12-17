/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mysort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:00:20 by rgallego          #+#    #+#             */
/*   Updated: 2021/12/17 20:39:30 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

void	ft_sortbase_a(t_queue *a)
{
	if (!ft_issorted(a))
	{
		if (a->head->num < a->head->next->num
			&& a->head->next->num > a->head->prvs->num)
			ft_reverse_rotate_a(a);
		else if (a->head->next->num < a->head->num
			&& a->head->num > a->head->prvs->num)
			ft_rotate_a(a);
		if (!ft_issorted(a))
			ft_swap_a(a);
	}
}
