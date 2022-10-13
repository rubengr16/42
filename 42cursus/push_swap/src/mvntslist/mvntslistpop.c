/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvntslistpop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:18:12 by rgallego          #+#    #+#             */
/*   Updated: 2022/10/11 18:23:42 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mvntslist.h"

/*
 * deletes one node from a mvntslist and returns it
 * INPUT:	t_mvntslist *mvntslist
 * OUTPUT:	t_lnode		:	deleted node with its next and previous pointers
 * 							set to NULL
 */
t_lnode	*mvntslistpop(t_mvntslist *mvntslist)
{
	t_lnode	*aux;

	aux = mvntslist->head;
	if (mvntslist->n_elem == 1)
		mvntslist->head = NULL;
	else if (mvntslist->n_elem > 1)
	{
		if (mvntslist->n_elem == 2)
		{
			aux->next->prvs = NULL;
			aux->prvs->next = NULL;
		}
		else
		{
			aux->next->prvs = aux->prvs;
			aux->prvs->next = aux->next;
		}
		mvntslist->head = mvntslist->head->next;
		aux->next = NULL;
		aux->prvs = NULL;
	}
	if (mvntslist->n_elem)
		mvntslist->n_elem--;
	return (aux);
}
