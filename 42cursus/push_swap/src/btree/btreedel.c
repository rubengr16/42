/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btreedel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:22:11 by rgallego          #+#    #+#             */
/*   Updated: 2022/08/30 16:44:02 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

static void	btreedelrec(t_btree *btree, t_bnode *bnode)
{
	if (!bnode)
		return ;
	btreedelrec(btree, bnode->left);
	bnode->left = NULL;
	btreedelrec(btree, bnode->right);
	bnode->right = NULL;
	free(bnode);
	btree->n_elem--;
}

void	btreedelall(t_btree *btree)
{
	if (!btree->n_elem)
		return ;
	btreedelrec(btree, btree->root);
	btree->root = NULL;
	free(btree);
	btree = NULL;
}
