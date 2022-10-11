/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:04:21 by rgallego          #+#    #+#             */
/*   Updated: 2022/10/11 15:32:42 by rgallego         ###   ########.fr       */
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
 * INPUT:	t_queue *queue, t_list *mvnts
 * OUTPUT:	void
 */
void	rotate(t_queue *queue, t_list *mvnts)
{
	char	*mvnt_name;

	if (!rotate_queue(queue))
		return ;
	mvnt_name = malloc(sizeof(char) * 3);
	mvnt_name[0] = 'r';
	mvnt_name[1] = queue->id;
	mvnt_name[2] = '\0';
	listadd_back_mvnt(mvnts, mvnt_name);
}

/*
 * function which rotates the given a and b queues simulltaneously
 * INPUT:	t_queue *a, t_queue *b, t_list *mvnts
 * OUTPUT:	void
 */
void	rotate_both(t_queue *a, t_queue *b, t_list *mvnts)
{
	char	*mvnt_name;

	if (rotate_queue(a))
	{
		if (rotate_queue(b))
		{
			mvnt_name = malloc(sizeof(char) * 3);
			mvnt_name[0] = 'r';
			mvnt_name[1] = 'rr';
			mvnt_name[2] = '\0';
			listadd_back_mvnt(mvnts, mvnt_name);
		}
		else
			reverse_rotate_queue(a);
	}
}
