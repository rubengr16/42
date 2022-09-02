/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bqueueinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:58:03 by rgallego          #+#    #+#             */
/*   Updated: 2022/09/02 19:42:16 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

/*
 * reserves memory using malloc and initializes its value root to NULL
 * INPUT:	void
 * OUTPUT:	t_btree *btree
 */
t_bqueue	*bqueueinit(void)
{
	t_bqueue	*bqueue;

	bqueue = malloc(sizeof(t_bqueue));
	if (!bqueue)
		return (NULL);
	bqueue->head = NULL;
	bqueue->tail = NULL;
	return (bqueue);
}

/*
 * reserves memory using malloc and initializes its value root to the given
 * node
 * INPUT:	t_bnode	*node
 * OUTPUT:	t_bqueue	*bqueue
 */
t_bqueue	*bqueueinitnode(t_bnode	*node)
{
	t_bqueue	*bqueue;

	bqueue = malloc(sizeof(t_bqueue));
	if (!bqueue)
		return (NULL);
	bqueue->head = node;
	bqueue->tail = node;
	return (bqueue);
}

/*
 * reserves memory using malloc and initializes its value root with a node
 * created with the given num
 * INPUT:	int		num
 * OUTPUT:	t_bqueue	*bqueue
 */
t_bqueue	*bqueueinitnum(int num)
{
	t_bqueue	*bqueue;
	t_bnode		*node;

	bqueue = malloc(sizeof(t_bqueue));
	if (!bqueue)
		return (NULL);
	node = newbnode(num);
	bqueue->head = node;
	bqueue->tail = node;
	return (bqueue);
}
