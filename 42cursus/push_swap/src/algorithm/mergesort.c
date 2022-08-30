/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergesort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:09:01 by rgallego          #+#    #+#             */
/*   Updated: 2022/08/30 21:18:45 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"
#include <stdio.h>

static void	make_divisions_btree(t_bnode *a, t_bnode *b)
{
	t_bnode	*a_left;
	t_bnode	*b_left;
	t_bnode	*a_right;
	t_bnode	*b_right;

	a_left = btreeadd_left_num(a, (a->num / 2));
	b_right = btreeadd_right_num(b, (b->num / 2));
	a_right = btreeadd_right_num(a, (a->num - a_left->num));
	b_left = btreeadd_left_num(b, (b->num - b_right->num));
	if (a_left->num < 3 && a_left->num < 3
		&& b_left->num < 3 && b_right->num < 3)
		return ;
	make_divisions_btree(a_left, b_right);
	make_divisions_btree(a_right, b_left);
}

void	print_preorder(t_bnode *bnode)
{
	if (!bnode)
		return ;
	printf("%d  ", bnode->num);
	print_preorder(bnode->left);
	print_preorder(bnode->right);
}

// NodoArbol p = raiz;
// Cola c = new Cola (); //c tiene datos de tipo NodoArbol
// if (p != null)
// c.encolar (p);
// while (!c.colaVacia ()) {
// p = c.desencolar ();
// System.out.print (p.getDato () + " ");
// if (p.getIzquierda () != null)
// c.encolar (p.getIzquierda ());
// if (p.getDerecha () != null)
// c.encolar (p.getDerecha ());
// }
// TO BE CONTINUED...
t_stack	*transform_btree_to_stack(t_bnode *btree)
{
	t_stack	*num_stack;
	t_bnode	*bnode_stack;
	t_bnode	*aux;

	if (!btree)
		return ;
	bnode_stack = NULL;
	bnode_stack = btreeadd_left(bnode_stack, btree);
	num_stack = malloc(sizeof(t_stack));
	num_stack->head = NULL;
	while (bnode_stack)
	{
		aux
	}
}

void	ft_mergesort(t_queue *a, t_queue *b, int half)
{
	t_bnode	*a_bt;
	t_bnode	*b_bt;
	t_stack	*a_s;
	t_stack	*b_s;

	while (b->n_elem < half)
	{
		if (a->head->num < half)
			push_b(a, b);
		else
			rotate_a(a);
	}
	a_bt = newbnode(a->n_elem);
	b_bt = newbnode(b->n_elem);
	make_divisions_btree(a_bt, b_bt);
	print_preorder(a_bt);
	print_preorder(b_bt);
	a_s = transform_btree_to_stack(a_bt);
	b_s = transform_btree_to_stack(b_bt);
	btreedelall(a_bt);
	btreedelall(b_bt);
}
