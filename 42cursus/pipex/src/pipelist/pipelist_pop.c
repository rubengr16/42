/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipelist_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:06:50 by rgallego          #+#    #+#             */
/*   Updated: 2022/09/21 22:14:48 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipelist.h"

t_pipe	*pipelistpop(t_pipelist *list)
{
	t_pipe	*aux;

	aux = list->head;
	if (list->head)
	{
		list->head = list->head->next;
		list->n_elem--;
	}
	return (aux);
}
