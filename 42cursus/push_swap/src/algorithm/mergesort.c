/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergesort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:09:01 by rgallego          #+#    #+#             */
/*   Updated: 2022/10/11 23:49:39 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

static void	make_divisions_btree_rec(t_bnode *a, t_bnode *b)
{
	t_bnode	*a_left;
	t_bnode	*b_left;
	t_bnode	*a_right;
	t_bnode	*b_right;

	a_left = btreeadd_left_num(a, (a->num / 2));
	b_right = btreeadd_right_num(b, (b->num / 2));
	a_right = btreeadd_right_num(a, (a->num - a_left->num));
	b_left = btreeadd_left_num(b, (b->num - b_right->num));
	if (a_left->num < 3 && a_right->num < 3
		&& b_left->num < 3 && b_right->num < 3)
		return ;
	make_divisions_btree_rec(a_left, b_left);
	make_divisions_btree_rec(a_right, b_right);
}

static void	make_divisions_btree(t_btree *a, t_btree *b)
{
	if (a->root->num > 2 || b->root->num > 2)
		make_divisions_btree_rec(a->root, b->root);
}

static t_stack	*transform_btrees_to_stack(t_btree *a_btree, t_btree *b_btree)
{
	t_stack		*num_stack;
	t_bqueue	*bqueue;
	t_bqnode	*aux;

	bqueue = bqueueinit();
	if (!bqueue)
		ft_error("Error. Failed to malloc.", STDERR_FILENO, ERR_USR);
	bqueueenqueuenode(bqueue, a_btree->root);
	bqueueenqueuenode(bqueue, b_btree->root);
	num_stack = stackinit();
	if (!num_stack)
		ft_error("Error. Failed to malloc.", STDERR_FILENO, ERR_USR);
	while (bqueue->head && bqueue->tail)
	{
		aux = bqueuedequeue(bqueue);
		(void)stackpush_num(num_stack, aux->bnode->num);
		if (aux->bnode->right)
			bqueueenqueuenode(bqueue, aux->bnode->right);
		if (aux->bnode->left)
			bqueueenqueuenode(bqueue, aux->bnode->left);
		free(aux);
	}
	free(bqueue);
	return (num_stack);
}

void	ft_mergesort(t_push_swap push_swap, int half)
{
	t_btree	*a_btree;
	t_btree	*b_btree;
	t_stack	*stack;

	while (push_swap.b->n_elem < half)
		push(push_swap.b, push_swap.a, push_swap.mvnts);
	a_btree = btreeinitnum(push_swap.a->n_elem);
	b_btree = btreeinitnum(push_swap.b->n_elem);
	make_divisions_btree(a_btree, b_btree);
	stack = transform_btrees_to_stack(a_btree, b_btree);
	the_algorithm(push_swap, stack);
	btreedelall(a_btree);
	btreedelall(b_btree);
	stackdelall(stack);
}

//                              50                                                            50
//               25                              25                              25                             25
//       12               13              12             13              12               13             12              13
//    6       6       6       7       6       6       6       7       6       6       6       7       6       6       6       7
//  3   3   3   3   3   3   3   4   3   3   3   3   3   3   3   4   3   3   3   3   3   3   3   4   3   3   3   3   3   3   3   4
// 1 2 1 2 1 2 1 2 1 2 1 2 1 2 2 2 1 2 1 2 1 2 1 2 1 2 1 2 1 2 2 2 1 2 1 2 1 2 1 2 1 2 1 2 1 2 2 2 1 2 1 2 1 2 1 2 1 2 1 2 1 2 2 2
