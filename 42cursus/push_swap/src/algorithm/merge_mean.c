/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_mean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:06:33 by rgallego          #+#    #+#             */
/*   Updated: 2022/12/23 18:45:00 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"
#include <stdio.h>

void fill_queue_b(t_push_swap push_swap)
{
	t_snode *a_mean;
	int	mean;

	while (push_swap.a->n_elem > 3)
	{
		a_mean = stackpop(push_swap.a_means);
		mean = (a_mean->max - a_mean->min) / 2;

	}
}

void	print_queue(t_queue queue)
{
	t_qnode	*node;
	int		i;

	printf("\n###### QUEUE ######");
	printf("\n 1: %d", queue.head->num);
	node = queue.head->next;
	i = 2;
	while (node != queue.head)
	{
		printf("\n %d: %d", i, node->num);
		node = node->next;
		i++;
	}
}

void	print_stack(t_stack stack)
{
	t_snode	*node;
	int		i;

	printf("\n###### STACK ######");
	printf("\n 1: [%d, %d]", stack.head->min, stack.head->max);
	node = stack.head->next;
	i = 2;
	while (node)
	{
		printf("\n %d: [%d, %d]", i, node->min, node->max);
		node = node->next;
		i++;
	}
}

void	merge_mean(t_push_swap push_swap)
{
	print_queue(*push_swap.a);
	algorithm_prep(*push_swap.a, push_swap.a_means);
	// fill_queue_b(push_swap);
	print_queue(*push_swap.a);
	print_stack(*push_swap.a_means);
}
