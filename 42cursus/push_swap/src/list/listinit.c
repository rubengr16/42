/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listinit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:47:23 by rgallego          #+#    #+#             */
/*   Updated: 2022/10/11 14:07:17 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

/*
 * reserves memory using malloc and initializes its values head and n_elem to
 * NULL and 0 respectively, meanwhile, id is set to the given char
 * INPUT:	void
 * OUTPUT:	t_list *list
 */
t_list	*listinit(void)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->head = NULL;
	list->n_elem = 0;
	return (list);
}
