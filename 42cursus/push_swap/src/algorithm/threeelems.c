/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threeelems.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:00:20 by rgallego          #+#    #+#             */
/*   Updated: 2023/02/14 22:11:32 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

/*
 * function which receives a queue and tells if it is sorted
 * INPUT:	t_queue *queue, int state
 * OUTPUT:	int	:	1	sorted
 *					0	not sorted
 */
int	is_sorted(t_queue *queue)
{
	t_qnode	*aux;

	if (queue->n_elem <= 1)
		return (1);
	aux = queue->head->next;
	while (aux != queue->head && aux->num > aux->prvs->num)
		aux = aux->next;
	if (aux != queue->head )
		return (0);
	return (1);
}

int	group_is_sorted(t_queue *queue, t_snode node)
{
	t_qnode	*aux;

	if (queue->n_elem <= 1 || node.size <= 1)
		return (1);
	aux = queue->head->next;
	while (aux != queue->head && node.size && aux->num > aux->prvs->num)
	{
		aux = aux->next;
		node.size--;
	}
	if (node.size)
		return (0);
	return (1);
}

/*
 *
 * INPUT:
 * OUTPUT:
 */
void	sort_base(t_queue *queue, t_mvntslist *mvnts)
{
	if (is_sorted(queue))
		return ;
	if (queue->n_elem == 3
		&& queue->head->num < queue->head->next->num
		&& queue->head->next->num > queue->head->prvs->num)
		reverse_rotate(queue, mvnts);
	else if (queue->n_elem == 3
		&& queue->head->next->num < queue->head->num
		&& queue->head->num > queue->head->prvs->num)
		rotate(queue, mvnts);
	if (!is_sorted(queue))
		swap(queue, mvnts);
}
