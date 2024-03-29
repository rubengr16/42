/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:00:20 by rgallego          #+#    #+#             */
/*   Updated: 2023/02/22 17:33:02 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

int	group_sorted(t_queue *queue, t_snode node)
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
	if (sorted(queue))
		return ;
	if (queue->n_elem == 3
		&& queue->head->num < queue->head->next->num
		&& queue->head->next->num > queue->head->prvs->num)
		rev_rotate(queue, mvnts);
	else if (queue->n_elem == 3
		&& queue->head->next->num < queue->head->num
		&& queue->head->num > queue->head->prvs->num)
		rotate(queue, mvnts);
	if (!sorted(queue))
		swap(queue, mvnts);
}

int	calc_median(int min, int max)
{
	return (((max + min) / 2) + ((max + min) % 2));
}

int	on_range(int min, int max, int value)
{
	return (min <= value && value <= max);
}
