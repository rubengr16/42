/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 19:00:58 by rgallego          #+#    #+#             */
/*   Updated: 2021/12/20 14:28:15 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

int	ft_issorted(t_queue *queue)
{
	t_node	*aux;

	aux = queue->head->next;
	while (aux != queue->head && aux->num > aux->prvs->num)
		aux = aux->next;
	if (aux == queue->head)
		return (1);
	else
		return (0);
}

void	ft_setsorted(t_queue *queue, int n)
{
	t_node	*aux;

	aux = queue->head;
	while (n)
	{
		aux->state = 0;
		n--;
	}
}
