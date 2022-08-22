/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:04:21 by rgallego          #+#    #+#             */
/*   Updated: 2022/08/22 18:51:40 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mvmnts.h"

/*
 * function which rotates a queue. This means that the first element of your
 * queue will be the last one
 * INPUT:	t_queue *queue
 * OUTPUT:	int	:	1	reverse rotate is fullfilled
 * 					0	reverse rotate has failed
 */
int	rotate_queue(t_queue *queue)
{
	if (queue->n_elem > 1)
	{
		queue->head = queue->head->next;
		return (1);
	}
	else
		return (0);
}

/*
 * function which rotates the given a queue 
 * INPUT:	t_queue *a
 * OUTPUT:	void
 */
void	rotate_a(t_queue *a)
{
	if (rotate_queue(a))
		ft_putendl_fd("ra", 1);
}

/*
 * function which rotates the given b queue 
 * INPUT:	t_queue *b
 * OUTPUT:	void
 */
void	rotate_b(t_queue *b)
{
	if (rotate_queue(b))
		ft_putendl_fd("rb", 1);
}

/*
 * function which rotates the given a and b queues simulltaneously
 * INPUT:	t_queue *a, t_queue *b
 * OUTPUT:	void
 */
void	rotate_ab(t_queue *a, t_queue *b)
{
	if (rotate_queue(a))
	{
		if (rotate_queue(b))
			ft_putendl_fd("rr", 1);
		else
			reverse_rotate_queue(a);
	}
}