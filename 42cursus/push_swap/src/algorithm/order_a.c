/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:37:19 by rgallego          #+#    #+#             */
/*   Updated: 2023/02/22 17:29:39 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

void	swap_optimizer(t_push_swap push_swap)
{
	if (push_swap.a->head && push_swap.b->head
		&& push_swap.a->head->num > push_swap.a->head->next->num
		&& push_swap.b->head->num < push_swap.b->head->next->num)
		swap_both(push_swap.a, push_swap.b, push_swap.mvnts);
	else if (push_swap.a->head
		&& push_swap.a->head->num > push_swap.a->head->next->num)
		swap(push_swap.a, push_swap.mvnts);
	else if (push_swap.b->head
		&& push_swap.b->head->num < push_swap.b->head->next->num)
		swap(push_swap.b, push_swap.mvnts);
}

void	three_elems_queue(t_queue *a, t_mvntslist *mvnts, t_snode *group)
{
	if (a->head->next && a->head->num > a->head->next->num)
		swap(a, mvnts);
	if (group_sorted(a, *group))
		return ;
	rotate(a, mvnts);
	if (a->head->next
		&& a->head->num > a->head->next->num)
		swap(a, mvnts);
	rev_rotate(a, mvnts);
	if (a->head->next
		&& a->head->num > a->head->next->num)
		swap(a, mvnts);
}

void	four_elems_queue(t_push_swap push_swap, t_snode *group)
{
	int	needed_rra;
	int	pushed;

	needed_rra = 0;
	pushed = 0;
	(void)make_new_groups(push_swap.a_mdn, group);
	group = push_swap.a_mdn->head;
	while (pushed < 2)
	{
		if (on_range(group->min, group->max, push_swap.a->head->num))
		{
			rotate(push_swap.a, push_swap.mvnts);
			needed_rra++;
		}
		else
		{
			push(push_swap.b, push_swap.a, push_swap.mvnts);
			pushed++;
		}
	}
	while (needed_rra--)
		rev_rotate(push_swap.a, push_swap.mvnts);
	swap_optimizer(push_swap);
	push(push_swap.a, push_swap.b, push_swap.mvnts);
	push(push_swap.a, push_swap.b, push_swap.mvnts);
}

void	order_a(t_push_swap push_swap, t_snode *group)
{
	if (group->size < push_swap.a->n_elem)
		while (on_range(group->min, group->max, push_swap.a->head->prvs->num))
			rev_rotate(push_swap.a, push_swap.mvnts);
	if (group->size == 1 || group_sorted(push_swap.a, *group))
	{
		free(group);
		return ;
	}
	else if (group->size == 2
		&& push_swap.a->head->num > push_swap.a->head->next->num)
		swap(push_swap.a, push_swap.mvnts);
	else if (group->size == 3)
		three_elems_queue(push_swap.a, push_swap.mvnts, group);
	else if (group->size == 4)
		four_elems_queue(push_swap, group);
	else
	{
		group = make_new_groups(push_swap.b_mdn, group);
		while (group->size)
			group->size -= move_nbs(push_swap.a, push_swap.b,
					push_swap.mvnts, *push_swap.b_mdn->head);
	}
	free(group);
}
