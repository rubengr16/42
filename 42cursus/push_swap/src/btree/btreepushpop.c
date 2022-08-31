/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btreepushpop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 09:25:56 by rgallego          #+#    #+#             */
/*   Updated: 2022/08/31 16:10:02 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

t_btree	*btreepush(t_btree *stack, t_bnode *bnode)
{
	if (!bnode)
		return (stack);
	if (!stack)
		stack = btreeinit();
	if (stack->root)
		bnode->stack = stack->root;
	else
		bnode->stack = NULL;
	stack->root = bnode;
	return (stack);
}

t_btree	*btreepushnum(t_btree *stack, int num)
{
	t_bnode	*bnode;

	if (!stack)
		stack = btreeinit();
	bnode = newbnode(num);
	return (btreepush(stack, bnode));
}

t_bnode	*btreepop(t_btree *stack)
{
	t_bnode	*aux;

	if (!stack)
		return (NULL);
	aux = stack->root;
	stack->root = stack->root->stack;
	aux->stack = NULL;
	return (aux);
}
