/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:42:13 by rgallego          #+#    #+#             */
/*   Updated: 2023/02/23 10:14:38 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mvnts.h"

/*
 * function which swaps the first element of the queue with the second one.
 * Ending the first element as the second and the second element as the
 * first one in the resulting mvntslist
 * INPUT:	t_queue *queue
 * OUTPUT:	int	:	1	swap is fullfilled
 * 					0	swap has failed
 */
int	swap_queue(t_queue *queue)
{
	if (queue->n_elem >= 1)
	{
		if (queue->n_elem == 2)
			(void)rotate_queue(queue);
		else if (queue->n_elem > 2)
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
void	swap(t_queue *queue, t_mvntslist *mvnts)
{
	char	*mvnt_name;

	if (!swap_queue(queue))
		return ;
	mvnt_name = malloc(sizeof(char) * 3);
	mvnt_name[0] = 's';
	mvnt_name[1] = queue->id;
	mvnt_name[2] = '\0';
	mvntslistadd_back_mvnt(mvnts, mvnt_name);
}

/*
 * function which makes the swap in the queue a and also in the queue b
 * INPUT:	t_queue *a, t_queue *b, t_mvntslist *mvnts
 * OUTPUT:	void
 */
void	swap_both(t_queue *a, t_queue *b, t_mvntslist *mvnts)
{
	char	*mvnt_name;

	if (swap_queue(a))
	{
		if (swap_queue(b))
		{
			mvnt_name = malloc(sizeof(char) * 3);
			mvnt_name[0] = 's';
			mvnt_name[1] = 's';
			mvnt_name[2] = '\0';
			mvntslistadd_back_mvnt(mvnts, mvnt_name);
		}
		else
			swap_queue(a);
	}
}
