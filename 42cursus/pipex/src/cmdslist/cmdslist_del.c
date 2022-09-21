/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdslist_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:10:37 by rgallego          #+#    #+#             */
/*   Updated: 2022/09/21 22:14:28 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmdslist.h"

void	cmdslistdelone(t_cmdslist *list)
{
	t_node	*aux;

	if (!list->n_elem)
		return ;
	aux = cmdslistpop(list);
	ft_free_split(aux->cmd_flag);
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
