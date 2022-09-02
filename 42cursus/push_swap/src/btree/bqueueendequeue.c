/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bqueueendequeue.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 09:25:56 by rgallego          #+#    #+#             */
/*   Updated: 2022/09/02 20:42:52 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

t_bqnode	*newbqnode(t_bnode *bnode)
{
	t_bqnode	*aux;

	aux = malloc(sizeof(t_bqnode));
	if (!aux)
		return (NULL);
	aux->bnode = bnode;
	aux->next = NULL;
	return (aux);
}

t_bqueue	*bqueueenqueue(t_bqueue *bqueue, t_bqnode *node)
{
	if (!node)
		return (bqueue);
	if (!bqueue)
		bqueue = bqueueinit();
	if (!bqueue->head && !bqueue->tail)
	{
		bqueue->head = node;
		bqueue->tail = node;
	}
	else
		bqueue->head->next = node;
	bqueue->head = node;
	node->next = NULL;
	return (bqueue);
}

t_bqueue	*bqueueenqueuenode(t_bqueue *queue, t_bnode *bnode)
{
	t_bqnode	*node;

	if (!queue)
		queue = bqueueinit();
	node = newbqnode(bnode);
	return (bqueueenqueue(queue, node));
}

t_bqnode	*bqueuedequeue(t_bqueue *queue)
{
	t_bqnode	*aux;

	if (!queue || !queue->tail)
		return (NULL);
	aux = queue->tail;
	if (queue->head == queue->tail)
		queue->head = queue->head->next;
	queue->tail = queue->tail->next;
	aux->next = NULL;
	return (aux);
}
