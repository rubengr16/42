/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listpop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:18:12 by rgallego          #+#    #+#             */
/*   Updated: 2022/08/30 16:08:11 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

/*
 * deletes one node from a list and returns it
 * INPUT:	t_list *list
 * OUTPUT:	t_lnode		:	deleted node with its next and previous pointers
 * 							set to NULL
 */
t_lnode	*listpop(t_list *list)
{
	t_lnode	*aux;

	aux = list->head;
	if (list->n_elem == 1)
		list->head = NULL;
	else if (list->n_elem > 1)
	{
		if (list->n_elem == 2)
		{
			aux->next->prvs = NULL;
			aux->prvs->next = NULL;
		}
		else
		{
			aux->next->prvs = aux->prvs;
			aux->prvs->next = aux->next;
		}
		list->head = list->head->next;
		aux->next = NULL;
		aux->prvs = NULL;
	}
	if (list->n_elem)
		list->n_elem--;
	return (aux);
}
