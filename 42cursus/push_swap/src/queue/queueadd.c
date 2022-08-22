/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queueadd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:53:55 by rgallego          #+#    #+#             */
/*   Updated: 2022/08/22 18:57:07 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

/*
 * function which receives a new node and establishes its value to num and its
 * pointer to NULL
 * INPUT:	int num
 * OUTPUT:	t_node
 */
t_node	*newnode(int num)
{
	t_node	*aux;

	aux = malloc(sizeof(t_node));
	if (aux)
	{
		aux->num = num;
		aux->next = aux;
		aux->prvs = aux;
	}
	return (aux);
}

/*
 * function which inserts a node received as argument at the back of a queue
 * INPUT:	t_queue *queue, t_node *node
 * OUTPUT:	void
 */
void	queueadd_back(t_queue *queue, t_node *node)
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
 * function which creates a node with the received number as argument and
 * inserts it at the back of a queue
 * INPUT:	t_queue *queue, int num
 * OUTPUT:	void
 */
void	queueadd_back_num(t_queue *queue, int num)
{
	t_node	*aux;

	aux = newnode(num);
	if (aux)
		queueadd_back(queue, aux);
}

/*
 * function which inserts a node received as argument at the front of a queue
 * INPUT:	t_queue *queue, t_node *node
 * OUTPUT:	void
 */
void	queueadd_front(t_queue *queue, t_node *node)
{
	queueadd_back(queue, node);
	queue->head = node;
}

/*
 * function which creates a node with the received number as argument and
 * inserts it at the front of a queue
 * INPUT:	t_queue *queue, int num
 * OUTPUT:	void
 */
void	queueadd_front_num(t_queue *queue, int num)
{
	t_node	*aux;

	aux = newnode(num);
	if (aux)
		queueadd_front(queue, aux);
}
