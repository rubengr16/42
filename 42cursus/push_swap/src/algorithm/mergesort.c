/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergesort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:09:01 by rgallego          #+#    #+#             */
/*   Updated: 2022/10/11 20:15:08 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"
#include <stdio.h>

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

	// a_right = btreeadd_right_num(a, (a->num / 2));
	// b_left = btreeadd_left_num(b, (b->num / 2));
	// a_left = btreeadd_left_num(a, (a->num - a_right->num));
	// b_right = btreeadd_right_num(b, (b->num - b_left->num));

	// a_left = btreeadd_left_num(a, (a->num / 2));
	// a_right = btreeadd_right_num(a, (a->num - a_left->num));
	// b_left = btreeadd_left_num(b, (b->num / 2));
	// b_right = btreeadd_right_num(b, (b->num - b_left->num));

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


void	print_preorder(t_bnode *bnode)
{
	if (!bnode)
		return ;
	printf("%d ", bnode->num);
	print_preorder(bnode->left);
	print_preorder(bnode->right);
}

void	print_stack(t_stack *stack)
{
	t_snode	*aux;

	if (!stack)
		return ;
	aux = stack->head;
	while (aux)
	{
		printf("%d ", aux->num);
		aux = aux->next;
	}
}

void	printqueue(t_queue queue)
{
	t_qnode	*aux;
	int		cnt;

	cnt = 0;
	aux = queue.head;
	while (cnt < queue.n_elem)
	{
		printf("Elem %d: %d\n", cnt, aux->num);
		aux = aux->next;
		cnt++;
	}
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
	t_stack	*a_stack;
	// t_stack	*b_stack;
	// t_stack	*the_stack;

	// write(1, "A\n\n", 3);
	// printqueue(*a);
	// write(1, "B\n\n", 3);
	// printqueue(*b);
	while (push_swap.b->n_elem < half)
	{
		// if (a->head->num < half)
		// 	push(b, a);
		// else
		// 	rotate(a);
		push(push_swap.b, push_swap.a, push_swap.mvnts);
	}
	a_btree = btreeinitnum(push_swap.a->n_elem);
	b_btree = btreeinitnum(push_swap.b->n_elem);
	make_divisions_btree(a_btree, b_btree);
	// print_preorder(a_btree->root);
	// print_preorder(b_btree->root);
	a_stack = transform_btrees_to_stack(a_btree, b_btree);
	// printf("\n\n##########################\n\n");
	// print_stack(a_stack);
	// write(1, "A\n\n", 3);
	// printqueue(*a);
	// write(1, "B\n\n", 3);
	// printqueue(*b);
	the_algorithm(push_swap, a_stack);
	// write(1, "A\n\n", 3);
	// printqueue(*a);
	// write(1, "B\n\n", 3);
	// printqueue(*b);
	// write(1, "\n\n", 2);
	// print_stack(a_stack);
	// print_stack(b_stack);
	btreedelall(a_btree);
	btreedelall(b_btree);
	stackdelall(a_stack);
	// stackdelall(b_stack);
}

//                              50                                                            50
//               25                              25                              25                             25
//       12               13              12             13              12               13             12              13
//    6       6       6       7       6       6       6       7       6       6       6       7       6       6       6       7
//  3   3   3   3   3   3   3   4   3   3   3   3   3   3   3   4   3   3   3   3   3   3   3   4   3   3   3   3   3   3   3   4
// 1 2 1 2 1 2 1 2 1 2 1 2 1 2 2 2 1 2 1 2 1 2 1 2 1 2 1 2 1 2 2 2 1 2 1 2 1 2 1 2 1 2 1 2 1 2 2 2 1 2 1 2 1 2 1 2 1 2 1 2 1 2 2 2
