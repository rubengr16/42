/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listadd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:53:55 by rgallego          #+#    #+#             */
/*   Updated: 2022/10/11 15:21:24 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

/*
 * creates a new lnode and establishes its value to mvnt and its
 * pointers
 * INPUT:	char *mvnt
 * OUTPUT:	t_lnode
 */
t_lnode	*newlnode(char *mvnt)
{
	t_lnode	*aux;

	aux = malloc(sizeof(t_lnode));
	if (!aux)
		return (NULL);
	aux->mvnt = mvnt;
	aux->next = aux;
	aux->prvs = aux;
	return (aux);
}

/*
 * inserts a lnode received as argument at the back of the list
 * INPUT:	t_list *list, t_lnode *node
 * OUTPUT:	void
 */
void	listadd_back(t_list *list, t_lnode *node)
{
	if (!list->n_elem)
		list->head = node;
	else if (list->n_elem == 1)
	{
		list->head->next = node;
		list->head->prvs = node;
		node->next = list->head;
		node->prvs = list->head;
	}
	else if (list->n_elem > 1)
	{
		node->prvs = list->head->prvs;
		node->next = list->head;
		node->next->prvs = node;
		node->prvs->next = node;
	}
	list->n_elem++;
}

/*
 * creates a lnode with the received movement as argument and
 * inserts it at the back of a list
 * INPUT:	t_list *list, char *mvnt
 * OUTPUT:	void
 */
t_lnode	*listadd_back_mvnt(t_list *list, char *mvnt)
{
	t_lnode	*aux;

	aux = newlnode(mvnt);
	if (!aux)
		return (NULL);
	listadd_back(list, aux);
	return (aux);
}

/*
 * inserts a lnode received as argument at the front of a list
 * INPUT:	t_list *list, t_lnode *node
 * OUTPUT:	void
 */
void	listadd_front(t_list *list, t_lnode *node)
{
	listadd_back(list, node);
	list->head = node;
}

/*
 * creates a lnode with the received number as argument and
 * inserts it at the front of a list
 * INPUT:	t_list *list, char *mvnt
 * OUTPUT:	void
 */
t_lnode	*listadd_front_mvnt(t_list *list, char *mvnt)
{
	t_lnode	*aux;

	aux = newlnode(mvnt);
	if (!aux)
		return (NULL);
	listadd_front(list, aux);
	return (aux);
}

