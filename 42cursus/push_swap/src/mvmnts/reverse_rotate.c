/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:17:16 by rgallego          #+#    #+#             */
/*   Updated: 2022/09/01 09:18:59 by rgallego         ###   ########.fr       */
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
int	reverse_rotate_queue(t_queue *queue)
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
 * function which reverse rotates the given queue
 * INPUT:	t_queue *queue
 * OUTPUT:	void
 */
void	reverse_rotate(t_queue *queue)
{
	if (!reverse_rotate_queue(queue))
		return ;
	ft_putchar_fd('r', STDOUT_FILENO);
	ft_putchar_fd(queue->id, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}

/*
 * function which reverse rotates the given a and b queues simultaneously
 * INPUT:	t_queue *a, t_queue *b
 * OUTPUT:	void
 */
void	reverse_rotate_both(t_queue *a, t_queue *b)
{
	if (reverse_rotate_queue(a))
	{
		if (reverse_rotate_queue(b))
			ft_putendl_fd("rrr", STDOUT_FILENO);
		else
			rotate_queue(a);
	}
}
