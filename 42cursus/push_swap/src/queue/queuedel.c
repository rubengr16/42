/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queuedel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:32:30 by rgallego          #+#    #+#             */
/*   Updated: 2022/08/29 17:44:50 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

/* function which deletes the first node of a queue
 * INPUT: 	t_queue *queue
 * OUTPUT:	void
 */
void	queuedelone(t_queue *queue)
{
	if (queue->n_elem)
		free(queuepop(queue));
}

/* function which deletes a queue
 * INPUT: 	t_queue **queue
 * OUTPUT:	void
 */
void	queuedelall(t_queue **queue)
{
	if (!(*queue))
		return ;
	while ((*queue)->n_elem)
		queuedelone(*queue);
		
	(*queue)->head = NULL;
	free(*queue);
	*queue = NULL;
}
