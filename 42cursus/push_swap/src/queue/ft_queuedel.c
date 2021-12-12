/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queuedel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:32:30 by rgallego          #+#    #+#             */
/*   Updated: 2021/12/13 00:23:58 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"
#include <stdio.h>

/* function which deletes the first node of a queue
 * INPUT: 	t_queue *queue
 * OUTPUT:	void
 */
void	ft_queuedelone(t_queue *queue)
{
	if (queue->n_elem)
		free(ft_queuepop(queue));
}

/* function which deletes a queue
 * INPUT: 	t_queue *queue
 * OUTPUT:	void
 */
void	ft_queuedelall(t_queue *queue)
{
	while (queue->n_elem)
	{
		printf("\nn_elem: %d, head->num: %d", queue->n_elem, queue->head->num);
		ft_queuedelone(queue);
	}
	printf("\nhead: %p", queue->head);
	queue->head = NULL;
	free(queue);
	printf("\nqueue: %p", queue);
	queue = NULL;
	printf("\nqueue (supposed nil): %p", queue);
}
