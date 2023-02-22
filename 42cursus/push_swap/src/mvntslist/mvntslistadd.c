/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvntslistadd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:53:55 by rgallego          #+#    #+#             */
/*   Updated: 2023/02/22 12:38:53 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mvntslist.h"

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
 * inserts a lnode received as argument at the back of the mvntslist
 * INPUT:	t_mvntslist *mvntslist, t_lnode *node
 * OUTPUT:	void
 */
void	mvntslistadd_back(t_mvntslist *mvntslist, t_lnode *node)
{
	if (!mvntslist->n_elem)
		mvntslist->head = node;
	else if (mvntslist->n_elem == 1)
	{
		mvntslist->head->next = node;
		mvntslist->head->prvs = node;
		node->next = mvntslist->head;
		node->prvs = mvntslist->head;
	}
	else if (mvntslist->n_elem > 1)
	{
		node->prvs = mvntslist->head->prvs;
		node->next = mvntslist->head;
		node->next->prvs = node;
		node->prvs->next = node;
	}
	mvntslist->n_elem++;
}

/*
 * creates a lnode with the received movement as argument and
 * inserts it at the back of a mvntslist
 * INPUT:	t_mvntslist *mvntslist, char *mvnt
 * OUTPUT:	void
 */
t_lnode	*mvntslistadd_back_mvnt(t_mvntslist *mvntslist, char *mvnt)
{
	t_lnode	*aux;

	aux = newlnode(mvnt);
	if (!aux)
		return (NULL);
	mvntslistadd_back(mvntslist, aux);
	return (aux);
}

/*
 * inserts a lnode received as argument at the front of a mvntslist
 * INPUT:	t_mvntslist *mvntslist, t_lnode *node
 * OUTPUT:	void
 */
void	mvntslistadd_front(t_mvntslist *mvntslist, t_lnode *node)
{
	mvntslistadd_back(mvntslist, node);
	mvntslist->head = node;
}

/*
 * creates a lnode with the received number as argument and
 * inserts it at the front of a mvntslist
 * INPUT:	t_mvntslist *mvntslist, char *mvnt
 * OUTPUT:	void
 */
t_lnode	*mvntslistadd_front_mvnt(t_mvntslist *mvntslist, char *mvnt)
{
	t_lnode	*aux;

	aux = newlnode(mvnt);
	if (!aux)
		return (NULL);
	mvntslistadd_front(mvntslist, aux);
	return (aux);
}
