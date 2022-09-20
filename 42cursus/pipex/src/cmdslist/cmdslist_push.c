/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdslist_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:45:37 by rgallego          #+#    #+#             */
/*   Updated: 2022/09/20 11:05:12 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmdslist.h"

t_node	*newnode(char *cmd, char *flag)
{
	t_node	*aux;

	aux = malloc(sizeof(t_node));
	if (!aux)
		return (NULL);
	aux->cmd = cmd;
	aux->flag = flag;
	aux->next = NULL;
	return (aux);
}
void	cmdslistpush(t_cmdslist *list, t_node *node)
{
	if (!node)
		return ;
	if (!list->n_elem)
	{
		list->head = node;
		list->tail = node;
	}
	else
		list->tail->next = node;
}

t_node	*cmdslistpush_cmd(t_cmdslist *list, char *cmd, char *flag)
{
	t_node	*aux;

	aux = newnode(cmd, flag);
	if (!aux)
		return (NULL);
	cmdslistpush(list, aux);
	return (aux);
}
