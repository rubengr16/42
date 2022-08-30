/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queueadd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:53:55 by rgallego          #+#    #+#             */
/*   Updated: 2022/08/30 16:08:06 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

/*
 * creates a new qnode and establishes its value to num and its
 * pointer to NULL
 * INPUT:	int num
 * OUTPUT:	t_qnode
 */
t_qnode	*newqnode(int num)
{
	t_qnode	*aux;

	aux = malloc(sizeof(t_qnode));
	if (!aux)
		return (NULL);
	aux->num = num;
	aux->next = aux;
	aux->prvs = aux;
	return (aux);
}

/*
 * inserts a qnode received as argument at the back of a queue
 * INPUT:	t_queue *queue, t_qnode *node
 * OUTPUT:	void
 */
void	queueadd_back(t_queue *queue, t_qnode *node)
{
	if (!queue->n_elem)
		queue->head = node;
	else if (queue->n_elem == 1)
	{
		queue->head->next = node;
		queue->head->prvs = node;
		node->next = queue->head;
		node->prvs = queue->head;
	}
	else if (queue->n_elem > 1)
	{
		node->prvs = queue->head->prvs;
		node->next = queue->head;
		node->next->prvs = node;
		node->prvs->next = node;
	}
	queue->n_elem++;
}

/*
 * creates a qnode with the received number as argument and
 * inserts it at the back of a queue
 * INPUT:	t_queue *queue, int num
 * OUTPUT:	void
 */
void	queueadd_back_num(t_queue *queue, int num)
{
	t_qnode	*aux;

	aux = newqnode(num);
	if (aux)
		queueadd_back(queue, aux);
}

/*
 * inserts a qnode received as argument at the front of a queue
 * INPUT:	t_queue *queue, t_qnode *node
 * OUTPUT:	void
 */
void	queueadd_front(t_queue *queue, t_qnode *node)
{
	queueadd_back(queue, node);
	queue->head = node;
}

/*
 * creates a qnode with the received number as argument and
 * inserts it at the front of a queue
 * INPUT:	t_queue *queue, int num
 * OUTPUT:	void
 */
void	queueadd_front_num(t_queue *queue, int num)
{
	t_qnode	*aux;

	aux = newqnode(num);
	if (aux)
		queueadd_front(queue, aux);
}
