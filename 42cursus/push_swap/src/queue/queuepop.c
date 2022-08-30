/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queuepop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:18:12 by rgallego          #+#    #+#             */
/*   Updated: 2022/08/30 16:08:11 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

/*
 * deletes one node from a queue and returns it
 * INPUT:	t_queue *queue
 * OUTPUT:	t_qnode		:	deleted node with its next and previous pointers
 * 							set to NULL
 */
t_qnode	*queuepop(t_queue *queue)
{
	t_qnode	*aux;

	aux = queue->head;
	if (queue->n_elem == 1)
		queue->head = NULL;
	else if (queue->n_elem > 1)
	{
		if (queue->n_elem == 2)
		{
			aux->next->prvs = NULL;
			aux->prvs->next = NULL;
		}
		else
		{
			aux->next->prvs = aux->prvs;
			aux->prvs->next = aux->next;
		}
		queue->head = queue->head->next;
		aux->next = NULL;
		aux->prvs = NULL;
	}
	if (queue->n_elem)
		queue->n_elem--;
	return (aux);
}
