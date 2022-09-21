/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdslist_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:06:50 by rgallego          #+#    #+#             */
/*   Updated: 2022/09/21 22:14:48 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmdslist.h"

t_node	*cmdslistpop(t_cmdslist *list)
{
	t_node	*aux;

	aux = list->head;
	if (list->head)
	{
		list->head = list->head->next;
		list->n_elem--;
	}
	return (aux);
}
