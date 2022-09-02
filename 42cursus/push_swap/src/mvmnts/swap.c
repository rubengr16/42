/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:42:13 by rgallego          #+#    #+#             */
/*   Updated: 2022/09/01 09:20:03 by rgallego         ###   ########.fr       */
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
 * function which makes the swap in the queue
 * INPUT:	t_queue *queue
 * OUTPUT:	void
 */
void	swap(t_queue *queue)
{
	if (!swap_queue(queue))
		return ;
	ft_putchar_fd('s', STDOUT_FILENO);
	ft_putchar_fd(queue->id, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}

/*
 * function which makes the swap in the queue a and also in the queue b
 * INPUT:	t_queue *a, t_queue *b
 * OUTPUT:	void
 */
void	swap_both(t_queue *a, t_queue *b)
{
	if (swap_queue(a))
	{
		if (swap_queue(b))
			ft_putendl_fd("ss", STDOUT_FILENO);
		else
			swap_queue(a);
	}
}
