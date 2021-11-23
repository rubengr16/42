/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queueadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:53:55 by rgallego          #+#    #+#             */
/*   Updated: 2021/11/23 17:41:29 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

/*
 * function which a new node and establishes its value to num and its pointer
 * to NULL
 * INPUT:	int num
 * OUTPUT:	t_node
 */
t_node	*ft_newnode(int num)
{
	t_node	*aux;

	aux = malloc(sizeof(t_node));
	if (aux)	
	{
		aux->num = num;
		aux->next = NULL;
		aux->prvs = NULL;
	}
	return (aux);
}

/*
 * function which inserts a node received as argument at the back of a queue
 * INPUT:	t_node *node, t_queue *queue
 * OUTPUT:	void
 */
void	ft_queueadd_back(t_node *node, t_queue *queue)
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
 * INPUT:	int num, t_queue *queue
 * OUTPUT:	void
 */
void	ft_queueadd_back_num(int num, t_queue *queue)
{
	t_node	*aux;

	aux = ft_newnode(num);
	if (aux)
		ft_queueadd_back(aux, queue);
}

/*
 * function which inserts a node received as argument at the front of a queue
 * INPUT:	t_node *node, t_queue *queue
 * OUTPUT:	void
 */
void	ft_queueadd_front(t_node *node, t_queue *queue)
{
	ft_queueadd_back(node, queue);
	queue->head = node;
}

/*
 * function which creates a node with the received number as argument and
 * inserts it at the front of a queue
 * INPUT:	int num, t_queue *queue
 * OUTPUT:	void
 */
void	ft_queueadd_front_num(int num, t_queue *queue)
{
	t_node	*aux;

	aux = ft_newnode(num);
	if (aux)
		ft_queueadd_front(aux, queue);
}
