/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btreeinit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:45:46 by rgallego          #+#    #+#             */
/*   Updated: 2022/08/30 16:34:47 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

/*
 * reserves memory using malloc and initializes its values
 * root and n_elem to NULL and 0 respectively
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
	btree->n_elem = 0;
	return (btree);
}
