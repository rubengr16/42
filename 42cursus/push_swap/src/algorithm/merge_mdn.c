/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_mdn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:06:33 by rgallego          #+#    #+#             */
/*   Updated: 2023/02/22 14:46:05 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

t_snode	*make_new_groups(t_stack *stack, t_snode	*group)
{
	int		mdn;

	if (group->size > 2)
	{
		mdn = calc_median(group->min, group->max);
		stackpush_minmax(stack, group->min, mdn - 1);
		stackpush_minmax(stack, mdn, group->max);
	}
	else
		stackpush_minmax(stack, group->min, group->max);
	return (group);
}

int	move_nbs(t_queue *q1, t_queue *q2, t_mvntslist *mvnts, t_snode group)
{
	if (q1->head->num <= group.max)
	{
		push(q2, q1, mvnts);
		if (q2->head->num < group.min)
			rotate(q2, mvnts);
		return (1);
	}
	rotate(q1, mvnts);
	return (0);
}

void	fill_queue_b(t_push_swap push_swap)
{
	t_snode	*group;
	int		cnt;
	int		mdn;

	while (push_swap.a->n_elem > 3)
	{
		group = stackpop(push_swap.a_mdn);
		mdn = calc_median(group->min, group->max);
		if ((group->max - mdn + 1) < 3)
			mdn = group->max - 2;
		stackpush_minmax(push_swap.a_mdn, mdn, group->max);
		snode_set_max(group, mdn - 1);
		group = make_new_groups(push_swap.b_mdn, group);
		cnt = group->size;
		while (cnt && push_swap.a->n_elem > 3)
			cnt -= move_nbs(push_swap.a, push_swap.b,
					push_swap.mvnts, *push_swap.b_mdn->head);
		free(group);
	}
}

void	merge_mdn(t_push_swap push_swap)
{
	algorithm_prep(*push_swap.a, push_swap.a_mdn);
	fill_queue_b(push_swap);
	sort_base(push_swap.a, push_swap.mvnts);
	free(stackpop(push_swap.a_mdn));
	while (push_swap.a_mdn->head || push_swap.b_mdn->head)
	{
		if (!push_swap.a_mdn->head)
			order_b(push_swap, stackpop(push_swap.b_mdn));
		else if (!push_swap.b_mdn->head)
			order_a(push_swap, stackpop(push_swap.a_mdn));
		else if (push_swap.a_mdn->head->max > push_swap.b_mdn->head->max)
			order_a(push_swap, stackpop(push_swap.a_mdn));
		else
			order_b(push_swap, stackpop(push_swap.b_mdn));
	}
	optimizer(push_swap.mvnts);
}
