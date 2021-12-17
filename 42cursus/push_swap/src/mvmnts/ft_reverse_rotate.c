/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:17:16 by rgallego          #+#    #+#             */
/*   Updated: 2021/12/17 20:41:39 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mvmnts.h"

	/*
	 * function which reverse rotates a queue. This means that the last element
	 * of your queue will be the first one
	 * INPUT:	t_queue *queue
 * OUTPUT:	int	:	1	reverse rotate is fullfilled
 * 					0	reverse rotate has failed
 */
int	ft_reverse_rotate_queue(t_queue *queue)
{
	if (queue->n_elem > 1)
	{
		queue->head = queue->head->prvs;
		return (1);
	}
	else
		return (0);
}

/*
 * function which reverse rotates the given a queue 
 * INPUT:	t_queue *a
 * OUTPUT:	void
 */
void	ft_reverse_rotate_a(t_queue *a)
{
	if (ft_reverse_rotate_queue(a))
		ft_putendl_fd("rra", 1);
}

/*
 * function which reverse rotates the given b queue 
 * INPUT:	t_queue *b
 * OUTPUT:	void
 */
void	ft_reverse_rotate_b(t_queue *b)
{
	if (ft_reverse_rotate_queue(b))
		ft_putendl_fd("rrb", 1);
}

/*
 * function which reverse rotates the given a and b queues simulltaneously
 * INPUT:	t_queue *a, t_queue *b
 * OUTPUT:	void
 */
void	ft_reverse_rotate_ab(t_queue *a, t_queue *b)
{
	if (ft_reverse_rotate_queue(a))
	{
		if (ft_reverse_rotate_queue(b))
			ft_putendl_fd("rrr", 1);
		else
			ft_rotate_queue(a);
	}
}
