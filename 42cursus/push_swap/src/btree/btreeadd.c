/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btreeadd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:34:16 by rgallego          #+#    #+#             */
/*   Updated: 2022/08/30 19:50:43 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

/*
 * creates a new bnode and establishes its value to num and its
 * pointer to NULL
 * INPUT:	int num
 * OUTPUT:	t_bnode
 */
t_bnode	*newbnode(int num)
{
	t_bnode	*aux;

	aux = malloc(sizeof(t_bnode));
	if (!aux)
		return (NULL);
	aux->num = num;
	aux->left = NULL;
	aux->right = NULL;
	return (aux);
}

/*
 * inserts a bnode received as argument at the left of a bnode
 * INPUT:	t_bnode *root, t_bnode *leaf
 * OUTPUT:	void
 */
void	btreeadd_left(t_bnode *root, t_bnode *leaf)
{
	if (!root)
		return ;
	root->left = leaf;
}

/*
 * creates a bnode with the received n as argument and
 * inserts it at the back of a bnode
 * INPUT:	t_bnode *root,  int num
 * OUTPUT:	void
 */
t_bnode	*btreeadd_left_num(t_bnode *root, int num)
{
	t_bnode	*aux;

	aux = newbnode(num);
	if (!aux)
		return (NULL);
	btreeadd_left(root, aux);
	return (aux);
}

/*
 * inserts a bnode received as argument at the right of a btree
 * INPUT:	t_bnode *root, t_bnode *leaf
 * OUTPUT:	void
 */
void	btreeadd_right(t_bnode *root, t_bnode *leaf)
{
	if (!root)
		return ;
	root->right = leaf;

}

/*
 * creates a bnode with the received number as argument and
 * inserts it at the back of a bnode
 * INPUT:	t_bnode *root, int n
 * OUTPUT:	void
 */
t_bnode	*btreeadd_right_num(t_bnode *root, int num)
{
	t_bnode	*aux;

	aux = newbnode(num);
	if (!aux)
		return (NULL);
	btreeadd_right(root, aux);
	return (aux);
}
