/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btreeinit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 09:52:36 by rgallego          #+#    #+#             */
/*   Updated: 2022/08/31 16:09:14 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

/*
 * reserves memory using malloc and initializes its value root to NULL
 * INPUT:	void
 * OUTPUT:	t_btree *btree
 */
t_btree	*btreeinit(void)
{
	t_btree	*btree;

	btree = malloc(sizeof(t_btree));
	if (!btree)
		return (NULL);
	btree->root = NULL;
	return (btree);
}

/*
 * reserves memory using malloc and initializes its value root to the given
 * bnode
 * INPUT:	t_bnode	*bnode
 * OUTPUT:	t_btree	*btree
 */
t_btree	*btreeinitnode(t_bnode	*bnode)
{
	t_btree	*btree;

	btree = malloc(sizeof(t_btree));
	if (!btree)
		return (NULL);
	btree->root = bnode;
	return (btree);
}

/*
 * reserves memory using malloc and initializes its value root with a node
 * created with the given num
 * INPUT:	int		num
 * OUTPUT:	t_btree	*btree
 */
t_btree	*btreeinitnum(int num)
{
	t_btree	*btree;
	t_bnode	*bnode;

	btree = malloc(sizeof(t_btree));
	if (!btree)
		return (NULL);
	bnode = newbnode(num);
	btree->root = bnode;
	return (btree);
}
