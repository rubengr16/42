/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mysort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:00:20 by rgallego          #+#    #+#             */
/*   Updated: 2021/12/20 15:31:43 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

void	ft_sortbase(t_queue *queue)
{
	if (!ft_issorted(queue))
	{
		if (queue->head->num < queue->head->next->num
			&& queue->head->next->num > queue->head->prvs->num)
			ft_reverse_rotate_a(queue);
		else if (queue->head->next->num < queue->head->num
			&& queue->head->num > queue->head->prvs->num)
			ft_rotate_a(queue);
		if (!ft_issorted(queue))
			ft_swap_a(queue);
	}
	ft_setstate(queue, 3, 0);
}

void	ft_sortrecavg(t_queue *a, t_queue *b, int lvl)
{
	int	avg;

	if (a->n_elem < 4)
		ft_sortbase_a(a);
	else
	{
		avg = ft_average(a);
		if (ft_n_rot(a, avg) <= ft_n_revrot(a, avg))
			ft_rotpush(a, b, avg, lvl);
		else
			ft_revrotpush(a, b, avg, lvl);
		ft_sortrecavg(a, b, lvl + 1);
	}

}
