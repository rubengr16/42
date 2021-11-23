/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:04:21 by rgallego          #+#    #+#             */
/*   Updated: 2021/11/23 18:45:50 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mvmnts.h"

/*
 * function which rotates a queue. This means that the first element ofyour
 * queue will be the last one
 * INPUT:	t_queue *queue
 * OUTPUT:	int	:	1	reverse rotate is fullfilled
 * 					0	reverse rotate has failed
 */

int	ft_rotate_queue(t_queue *queue)
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
void	ft_rotate_a(t_queue *a)
{
	if (ft_rotate_queue(a))
		ft_putendl_fd("ra", 1);
}

/*
 * function which rotates the given b queue 
 * INPUT:	t_queue *b
 * OUTPUT:	void
 */
void	ft_rotate_b(t_queue *b)
{
	if (ft_rotate_queue(a))
		ft_putendl_fd("rb", 1);
}

/*
 * function which rotates the given a and b queues simulltaneously
 * INPUT:	t_queue *a, t_queue *b
 * OUTPUT:	void
 */
void	ft_rotate_ab(t_queue *a, t_queue *b)
{
	if (ft_rotate_queue(a))
	{
		if (ft_rotate_queue(b))
			ft_putendl_fd("rr", 1);
		else
			ft_reverse_rotate_queue(a);
	}
}
