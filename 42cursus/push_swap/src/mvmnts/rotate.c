/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:04:21 by rgallego          #+#    #+#             */
/*   Updated: 2022/09/01 09:09:36 by rgallego         ###   ########.fr       */
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
 * function which rotates the given queue
 * INPUT:	t_queue *queue
 * OUTPUT:	void
 */
void	rotate(t_queue *queue)
{
	if (!rotate_queue(queue))
		return ;
	ft_putchar_fd('r', STDOUT_FILENO);
	ft_putchar_fd(queue->id, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}

/*
 * function which rotates the given a and b queues simulltaneously
 * INPUT:	t_queue *a, t_queue *b
 * OUTPUT:	void
 */
void	rotate_both(t_queue *a, t_queue *b)
{
	if (rotate_queue(a))
	{
		if (rotate_queue(b))
			ft_putendl_fd("rr", STDOUT_FILENO);
		else
			reverse_rotate_queue(a);
	}
}
