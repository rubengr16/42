/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mysort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:00:20 by rgallego          #+#    #+#             */
/*   Updated: 2022/08/22 19:09:54 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

/*
 * function which receives a queue and tells if it is sorted
 * INPUT:	t_queue *queue, int state
 * OUTPUT:	int	:	1	sorted
 *					0	not sorted
 */
static int	issorted(t_queue *queue)
{
	t_node	*aux;

	if (queue->n_elem <= 1)
		return (1);
	aux = queue->head->next;
	while (aux != queue->head && aux->num > aux->prvs->num)
		aux = aux->next;
	if (aux->num < aux->prvs->num)
		return (0);
	return (1);
}

/*
 * 
 * INPUT:	
 * OUTPUT:	
 */
int	sortbase(t_queue *queue)
{
	if (!issorted(queue))
	{
		if (queue->head->num < queue->head->next->num
			&& queue->head->next->num > queue->head->prvs->num)
			reverse_rotate_a(queue);
		else if (queue->head->next->num < queue->head->num
			&& queue->head->num > queue->head->prvs->num)
			rotate_a(queue);
		if (!issorted(queue))
			swap_a(queue);
	}
	return (1);
}


