/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 19:00:58 by rgallego          #+#    #+#             */
/*   Updated: 2021/12/20 17:35:01 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

/*
 * function which receives a queue and tells if it is sorted
 * INPUT:	t_queue *queue, int state
 * OUTPUT:	int	:	1	sorted
 *					0	not sorted
 */
int	ft_issorted(t_queue *queue, int state)
{
	t_node	*aux;

	if (queue->n_elem <= 1)
		return (1);
	aux = queue->head->next;
	while (aux != queue->head && aux->state == state
		&& aux->num > aux->prvs->num)
		aux = aux->next;
	if (aux->num < aux->prvs->num)
		return (0);
	return (1);
}

/*
 * function which sets the state of n_elems of queue to state
 * INPUT:	t_queue *queue, int n_elem, int state
 * OUTPUT:	void
 */
void	ft_setstate(t_queue *queue, int n_elem, int state)
{
	t_node	*aux;

	if (queue && n_elem)
	{
		queue->head->state = state;
		n_elem--;
		aux = queue->head->next;
		while (aux != queue->head && n_elem)
		{
			aux->state = state;
			aux = aux->next;
			n_elem--;
		}
	}
}

/*
 * function which receives a queue of integers and calculates the average of
 * the elements
 * INPUT:	t_queue *queue
 * OUTPUT:	int
 */
int	ft_average(t_queue *queue)
{
	int		sum;
	t_node	*aux;

	if (!queue || !queue->n_elem)
		return (0);
	sum = queue->head->num;
	if (queue->n_elem > 1)
	{
		aux = queue->head->next;
		while (aux != queue->head)
		{
			if (aux->state)
				sum += aux->num;
			aux = aux->next;
		}
	}
	return (sum / queue->n_elem);
}

/*
 * 
 * INPUT:	
 * OUTPUT:	
 */
int	ft_count_lvl(t_queue *queue, int lvl)
{
	int		n_elem;
	t_node	*aux;

	n_elem = 0;
	if (queue && queue->n_elem && queue->head->state == lvl)
	{
		n_elem++;
		aux = queue->head->next;
		while (aux != queue->head && aux->state == lvl)
		{
			n_elem++;
			aux = aux->next;
		}
	}
	return (n_elem);
}
