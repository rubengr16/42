/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_mdn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:06:33 by rgallego          #+#    #+#             */
/*   Updated: 2023/01/31 14:18:43 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"
#include <stdio.h>

void	fill_queue_b(t_push_swap push_swap)
{
	t_snode	*aux_mdn;
	int		mdn;
	int		cnt;

	while (push_swap.a->n_elem > 3)
	{
		aux_mdn = stackpop(push_swap.a_mdn);
		// printf("%d %d\n", aux_mdn->min, aux_mdn->max);
		mdn = calc_median(aux_mdn->min, aux_mdn->max);
		stackpush_minmax(push_swap.a_mdn, mdn, aux_mdn->max);
		aux_mdn->max = mdn - 1;
		cnt = (aux_mdn->max - aux_mdn->min) + 1;
		if (cnt > 2)
		{
			mdn = calc_median(aux_mdn->min, aux_mdn->max);
			// printf("mdn. %d\n", mdn);
			// printf("Group bottom. %d %d\n", aux_mdn->min, mdn - 1);
			stackpush_minmax(push_swap.b_mdn, aux_mdn->min, mdn - 1);
			// printf("Group top. %d %d\n", mdn, aux_mdn->max);
			stackpush_minmax(push_swap.b_mdn, mdn, aux_mdn->max);
		}
		// printf("B. %d %d\n", aux_mdn->min, aux_mdn->max);
		while (cnt)
		{
			if (push_swap.a->head->num <= aux_mdn->max)
			{
				push(push_swap.b, push_swap.a, push_swap.mvnts);
				if (push_swap.b->head->num < push_swap.b_mdn->head->min)
				{
					// write(1, "HOLAAAAAAAAAAA", 14);
					rotate(push_swap.b, push_swap.mvnts);
				}
				cnt--;
			}
			else
				rotate(push_swap.a, push_swap.mvnts);
			// printf("%d\n", cnt);
		}
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

void	merge_mdn(t_push_swap push_swap)
{
	// print_queue(*push_swap.a);
	algorithm_prep(*push_swap.a, push_swap.a_mdn);
	fill_queue_b(push_swap);
	optimizer(push_swap.mvnts);
	// print_queue(*push_swap.a);
	// print_stack(*push_swap.a_mdn);
}
