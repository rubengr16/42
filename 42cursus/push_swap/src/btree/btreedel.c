/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btreedel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:22:11 by rgallego          #+#    #+#             */
/*   Updated: 2022/08/31 15:47:54 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"
#include <unistd.h>

static void	btreedelrec(t_bnode *bnode)
{
	if (!bnode)
		return ;
	btreedelrec(bnode->left);
	if (bnode->left)
		bnode->left = NULL;
	btreedelrec(bnode->right);
	if (bnode->right)
		bnode->right = NULL;
	btreedelrec(bnode->stack);
	if (bnode->stack)
		bnode->stack = NULL;
	free(bnode);
}

void	btreedelall(t_btree *btree)
{
	if (!btree || !btree->root)
		return ;
	btreedelrec(btree->root);
	btree->root = NULL;
	free(btree);
	btree = NULL;
}
