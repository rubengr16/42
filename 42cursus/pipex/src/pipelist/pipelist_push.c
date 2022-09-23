/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipelist_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:45:37 by rgallego          #+#    #+#             */
/*   Updated: 2022/09/21 22:15:17 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipelist.h"

t_pipe	*newpipe(void)
{
	t_pipe	*aux;

	aux = malloc(sizeof(t_pipe));
	if (!aux)
		return (NULL);
	aux->next = NULL;
	return (aux);
}

t_pipelist	*pipelistpush(t_pipelist *list)
{
	t_pipe	*aux;

	aux = newpipe();
	if (!aux)
		return (NULL);
	if (!list->n_elem)
		list->head = aux;
	else
		list->tail->next = aux;
	list->tail = aux;
	list->n_elem++;
	return (list);
}

t_pipelist	*pipelistpush_pipe(t_pipelist *list, t_pipe *pipe)
{
	if (!pipe)
		return (NULL);
	if (!list->n_elem)
		list->head = pipe;
	else
		list->tail->next = pipe;
	list->tail = pipe;
	list->n_elem++;
	return (list);
}
