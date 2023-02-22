/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:17:16 by rgallego          #+#    #+#             */
/*   Updated: 2023/02/22 12:38:31 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mvmnts.h"

/*
 * function which reverse rotates a queue. This mdn that the last element
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
 * INPUT:	t_queue *queue, t_mvntslist *mvnts
 * OUTPUT:	void
 */
void	reverse_rotate(t_queue *queue, t_mvntslist *mvnts)
{
	char	*mvnt_name;

	if (!reverse_rotate_queue(queue))
		return ;
	mvnt_name = malloc(sizeof(char) * 4);
	mvnt_name[0] = 'r';
	mvnt_name[1] = 'r';
	mvnt_name[2] = queue->id;
	mvnt_name[3] = '\0';
	mvntslistadd_back_mvnt(mvnts, mvnt_name);
}

/*
 * function which reverse rotates the given a and b queues simultaneously
 * INPUT:	t_queue *a, t_queue *b, t_mvntslist *mvnts
 * OUTPUT:	void
 */
void	reverse_rotate_both(t_queue *a, t_queue *b, t_mvntslist *mvnts)
{
	char	*mvnt_name;

	if (reverse_rotate_queue(a))
	{
		if (reverse_rotate_queue(b))
		{
			mvnt_name = malloc(sizeof(char) * 4);
			mvnt_name[0] = 'r';
			mvnt_name[1] = 'r';
			mvnt_name[2] = 'r';
			mvnt_name[3] = '\0';
			mvntslistadd_back_mvnt(mvnts, mvnt_name);
		}
		else
			rotate_queue(a);
	}
}
