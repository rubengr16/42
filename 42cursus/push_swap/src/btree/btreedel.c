/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btreedel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:22:11 by rgallego          #+#    #+#             */
/*   Updated: 2022/09/02 19:05:42 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

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
