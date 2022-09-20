/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:10:37 by rgallego          #+#    #+#             */
/*   Updated: 2022/09/20 11:48:36 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	listdelone(t_list *list)
{
	t_node	*aux;
	if (!list->n_elem)
		return ;
	aux = listpop(list);
	free(aux->cmd);
	free(aux->flag);
	free(aux);
}

void	listdelall(t_list *list)
{
	if (!list)
		return ;
	while (list->n_elem)
		listdelone(list);
	list->head = NULL;
	list->tail = NULL;
	free(list);
	list = NULL;
}
