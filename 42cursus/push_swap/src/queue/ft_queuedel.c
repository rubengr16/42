/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queuedel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:32:30 by rgallego          #+#    #+#             */
/*   Updated: 2021/12/02 11:52:52 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "queue.h"

/* function which deletes the first node of a queue
 * INPUT: 	t_queue *queue
 * OUTPUT:	void
 */
void	ft_queuedelone(t_queue *queue)
{
	if (queue->n_elem)
	{
		free(ft_queuepop(queue));
		queue->n_elem--;
	}
}

/* function which deletes a queue
 * INPUT: 	t_queue *queue
 * OUTPUT:	void
 */
void	ft_queuedelall(t_queue *queue)
{
	while (queue->n_elem)
		ft_queuedelone(queue);
	queue->head = NULL;
	free(queue);
}
