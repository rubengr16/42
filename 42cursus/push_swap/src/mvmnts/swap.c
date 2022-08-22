/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:42:13 by rgallego          #+#    #+#             */
/*   Updated: 2022/08/22 19:08:13 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mvmnts.h"

/*
 * function which swaps the first element of the queue with the second one.
 * Ending the first element as the second and the second element as the
 * first one in the resulting list
 * INPUT:	t_queue *queue
 * OUTPUT:	int	:	1	swap is fullfilled
 * 					0	swap has failed
 */
static int	swap_queue(t_queue *queue)
{
	if (queue->n_elem > 1)
	{
		if (queue->n_elem == 2)
			(void)rotate_queue(queue);
		else
		{
			queue->head->next->prvs = queue->head->prvs;
			queue->head->prvs->next = queue->head->next;
			queue->head->prvs = queue->head->next;
			queue->head->next = queue->head->next->next;
			queue->head->next->prvs = queue->head;
			queue->head->prvs->next = queue->head;
			queue->head = queue->head->prvs;
		}
		return (1);
	}
	else
		return (0);
}

/*
 * function which makes the swap in the queue a
 * INPUT:	t_queue *a
 * OUTPUT:	void
 */
void	swap_a(t_queue *a)
{
	if (swap_queue(a))
		ft_putendl_fd("sa", 1);
}

/*
 * function which makes the swap in the queue b
 * INPUT:	t_queue *b
 * OUTPUT:	void
 */
void	swap_b(t_queue *b)
{
	if (swap_queue(b))
		ft_putendl_fd("sb", 1);
}

/*
 * function which makes the swap in the queue a and also in the queue b
 * INPUT:	t_queue *a, t_queue *b
 * OUTPUT:	void
 */
void	swap_ab(t_queue *a, t_queue *b)
{
	if (swap_queue(a))
	{
		if (swap_queue(b))
			ft_putendl_fd("ss", 1);
		else
			swap_queue(a);
	}
}
