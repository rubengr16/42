/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:50:44 by rgallego          #+#    #+#             */
/*   Updated: 2023/02/22 17:29:41 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

void	order_b(t_push_swap push_swap, t_snode *group)
{
	if (group->size < push_swap.b->n_elem)
		while (on_range(group->min, group->max, push_swap.b->head->prvs->num))
			rev_rotate(push_swap.b, push_swap.mvnts);
	if (group->size == 1)
		push(push_swap.a, push_swap.b, push_swap.mvnts);
	else if (group->size == 2)
	{
		push(push_swap.a, push_swap.b, push_swap.mvnts);
		push(push_swap.a, push_swap.b, push_swap.mvnts);
		if (push_swap.a->head->next
			&& push_swap.a->head->num > push_swap.a->head->next->num)
			swap(push_swap.a, push_swap.mvnts);
	}
	else if (!group_sorted(push_swap.b, *group))
	{
		group = make_new_groups(push_swap.a_mdn, group);
		while (group->size)
			group->size -= move_nbs(push_swap.b, push_swap.a,
					push_swap.mvnts, *push_swap.a_mdn->head);
	}
	free(group);
}
