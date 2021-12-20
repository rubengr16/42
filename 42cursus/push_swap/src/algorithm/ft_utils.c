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

int	ft_issorted(t_queue *queue, int state)
{
	t_node	*aux;

	if (queue && queue->n_elem > 1)
	{
		aux = queue->head->next;
		while (aux != queue->head && aux->state == state
			&& aux->num > aux->prvs->num)
			aux = aux->next;
		if (aux == queue->head)
			return (1);
		else
			return (0);
	}
	else
		return (1);
}

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

int	ft_average(t_queue *queue)
{
	int		sum;
	t_node	*aux;

	sum = 0;
	if (queue && queue->n_elem)
	{
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
	else
		return (0);
}

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
