/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdslist_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:18:45 by rgallego          #+#    #+#             */
/*   Updated: 2022/09/21 22:14:39 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmdslist.h"

t_cmdslist	*cmdslistinit(void)
{
	t_cmdslist	*list;

	list = malloc(sizeof(t_cmdslist));
	if (!list)
		return (NULL);
	list->n_elem = 0;
	list->head = NULL;
	list->tail = NULL;
	return (list);
}
