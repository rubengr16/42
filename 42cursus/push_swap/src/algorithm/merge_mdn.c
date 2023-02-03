/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_mdn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:06:33 by rgallego          #+#    #+#             */
/*   Updated: 2023/02/03 01:14:27 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"
#include <stdio.h>

t_snode	*make_new_groups(t_stack *stack2, t_snode	*group)
{
	int		mdn;

	if (group->size > 2)
	{
		mdn = calc_median(group->min, group->max);
		stackpush_minmax(stack2, group->min, mdn - 1);
		stackpush_minmax(stack2, mdn, group->max);
	}
	else
		stackpush(stack2, group);
	return (group);
}

int	move_numbers(t_queue *q1, t_queue *q2, t_mvntslist *mvnts, t_snode group)
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
		// printf("======================================");
		// printf("\n[%d, %d]\n", group->min, group->max);
		// printf("======================================");
		mdn = calc_median(group->min, group->max);
		// printf("======================================");
		// printf("\nmdn = %d\n", mdn);
		// printf("======================================");
		if ((group->max - mdn + 1) < 3)
			mdn = group->max - 2;
		// printf("======================================");
		// printf("\nmdn = %d\n", mdn);
		// printf("======================================");
		stackpush_minmax(push_swap.a_mdn, mdn, group->max);
		snode_set_max(group, mdn - 1);
		group = make_new_groups(push_swap.b_mdn, group);
		cnt = group->size;
		while (cnt && push_swap.a->n_elem > 3)
			cnt -= move_numbers(push_swap.a, push_swap.b,
					push_swap.mvnts, *push_swap.b_mdn->head);
	}
	// printf("\n$$$$$$$$$$   A   $$$$$$$$$$$$$$$");
	// print_queue(*push_swap.a);
	// // push_swap.b_mdn->head->max -= cnt;
	// printf("\n--------------------------");
	// print_stack(*push_swap.a_mdn);
	// print_stack(*push_swap.b_mdn);
	// printf("\ncnt = %d\n", cnt);
	// printf("\n--------------------------");
}

void	order(t_push_swap push_swap)
{
	t_snode	*group;
	int		decision;
	int		cnt;

	// printf("\n--------------------------");
	// print_stack(*push_swap.a_mdn);
	// print_stack(*push_swap.b_mdn);
	// printf("\n$$$$$$$$$$   A   $$$$$$$$$$$$$$$");
	// print_queue(*push_swap.a);
	// printf("\n$$$$$$$$$$   B   $$$$$$$$$$$$$$$");
	// print_queue(*push_swap.b);
	if (!push_swap.a_mdn->head)
		decision = 0;
	else if (!push_swap.b_mdn->head)
		decision = 1;
	else
		decision = push_swap.a_mdn->head->max > push_swap.b_mdn->head->max;
	// write(1, "hola\n", 5);
	// printf("\n!!!!!!!!!!!!GROUP!!!!!!!!!!!!![%d]", decision);
	if (decision)
		group = stackpop(push_swap.a_mdn);
	else
		group = stackpop(push_swap.b_mdn);
	// printf("======================================");
	// printf("\n[%d, %d]\n", group->min, group->max);
	// printf("======================================");
	cnt = group->size;
	if (decision
		&& push_swap.a->head && push_swap.a->head->prvs
		&& group->min <= push_swap.a->head->prvs->num && push_swap.a->head->prvs->num <= group->max
		&& group->size != push_swap.a->n_elem)
	{
		while(cnt)
		{
			reverse_rotate(push_swap.a, push_swap.mvnts);
			cnt--;
		}
	}
	else if (push_swap.b->head && push_swap.b->head->prvs && group->min <= push_swap.b->head->prvs->num && push_swap.b->head->prvs->num <= group->max
			&& group->size != push_swap.b->n_elem)
	{
		while(cnt)
		{
			reverse_rotate(push_swap.b, push_swap.mvnts);
			cnt--;
		}
	}
	cnt = group->size;
	if (decision && cnt == 1 && push_swap.a->head && group->min <= push_swap.a->head->num && push_swap.a->head->num <= group->max)
		return ;
	else if (cnt == 1 && push_swap.b->head && group->min <= push_swap.b->head->num && push_swap.b->head->num <= group->max)
		push(push_swap.a, push_swap.b, push_swap.mvnts);
	else if (decision && cnt == 2 && push_swap.a->head && group->min <= push_swap.a->head->num && push_swap.a->head->num <= group->max)
	{
		if (push_swap.a->head->next && push_swap.a->head->num > push_swap.a->head->next->num)
			swap(push_swap.a, push_swap.mvnts);
	}
	else if (cnt == 2 && push_swap.b->head && group->min <= push_swap.b->head->num && push_swap.b->head->num <= group->max)
	{
		push(push_swap.a, push_swap.b, push_swap.mvnts);
		push(push_swap.a, push_swap.b, push_swap.mvnts);
		if (push_swap.a->head->next && push_swap.a->head->num > push_swap.a->head->next->num)
			swap(push_swap.a, push_swap.mvnts);
	}
	else if (decision && push_swap.a->head && group->min <= push_swap.a->head->num && push_swap.a->head->num <= group->max)
	{
		// write(1, "hola\n", 5);
		group = make_new_groups(push_swap.b_mdn, group);
		cnt = group->size;
		while (cnt)
			cnt -= move_numbers(push_swap.a, push_swap.b,
					push_swap.mvnts, *push_swap.b_mdn->head);
	}
	else if (push_swap.b->head && group->min <= push_swap.b->head->num && push_swap.b->head->num <= group->max)
	{
		group = make_new_groups(push_swap.a_mdn, group);
		// printf("\n%d, %d\n", push_swap.a_mdn->head->min, push_swap.a_mdn->head->max);
		// if (push_swap.a_mdn->head->next)
		// 	printf("\n%d, %d\n", push_swap.a_mdn->head->next->min, push_swap.a_mdn->head->next->max);
		cnt = group->size;
		while (cnt)
			cnt -= move_numbers(push_swap.b, push_swap.a,
					push_swap.mvnts, *push_swap.a_mdn->head);
	}
}

void	print_queue(t_queue queue)
{
	t_qnode	*node;
	int		i;

	printf("\n###### QUEUE ######");
	if (!queue.head)
		return ;
	printf("\n 1: %d", queue.head->num);
	node = queue.head->next;
	i = 2;
	while (node && node != queue.head)
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
	if (!stack.head)
		return ;
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
	sort_base(push_swap.a, push_swap.mvnts);
	stackpop(push_swap.a_mdn);
	// print_stack(*push_swap.a_mdn);
	// print_stack(*push_swap.b_mdn);
	while(push_swap.a_mdn->head || push_swap.b_mdn->head)
		order(push_swap);
	optimizer(push_swap.mvnts);
	// print_queue(*push_swap.a);
	// print_stack(*push_swap.a_mdn);
}
