/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdslist_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:10:37 by rgallego          #+#    #+#             */
/*   Updated: 2022/09/20 11:48:36 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmdslist.h"

void	cmdslistdelone(t_cmdslist *list)
{
	t_node	*aux;
	if (!list->n_elem)
		return ;
	aux = cmdslistpop(list);
	free(aux->cmd);
	free(aux->flag);
	free(aux);
}

void	cmdslistdelall(t_cmdslist *list)
{
	if (!list)
		return ;
	while (list->n_elem)
		cmdslistdelone(list);
	list->head = NULL;
	list->tail = NULL;
	free(list);
	list = NULL;
}
