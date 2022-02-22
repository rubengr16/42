/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mysort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:00:20 by rgallego          #+#    #+#             */
/*   Updated: 2021/12/20 17:34:59 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

/*
 * 
 * INPUT:	
 * OUTPUT:	
 */
int	ft_sortbase(t_queue *queue)
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
	ft_setsorted(queue, 3);
	return (1);
}

/*
 * 
 * INPUT:	
 * OUTPUT:	
 */
int	ft_pushbck(t_queue *a, t_queue *b, int lvl)
{
	if (b && b->n_elem)
		while (b->head->state == lvl)
			ft_push_a(a, b);
	return (0);
}

int	ft_pushbcksorted(t_queue *a, t_queue *b, int lvl)
{
	/******************** DUMMIE **********************/
	(void)a;
	(void)b;
	return (lvl);
}

/*
 * 
 * INPUT:	
 * OUTPUT:	
 */
int	ft_sortrecavg(t_queue *a, t_queue *b, int lvl)
{
	int	avg;
	int	n_rot;

	if (a->n_elem < 4)
		return (ft_sortbase(a));
	else
	{
		avg = ft_average(a);
		n_rot = ft_n_rot(a, avg);
		while (n_rot < a->n_elem)
		{
			if (n_rot <= ft_n_revrot(a, avg))
				ft_rotpush(a, b, avg, lvl);
			else
				ft_revrotpush(a, b, avg, lvl);
			n_rot = ft_n_rot(a, avg);
		}
		if (ft_sortrecavg(a, b, lvl + 1) && ft_count_lvl(b, lvl) < 4)
			return (ft_pushbcksorted(a, b, lvl));
		else
			return (ft_pushbck(a, b, lvl));
	}
}
