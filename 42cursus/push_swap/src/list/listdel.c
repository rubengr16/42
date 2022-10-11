/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listdel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:32:30 by rgallego          #+#    #+#             */
/*   Updated: 2022/08/30 16:38:57 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

/* function which deletes the first node of a list
 * INPUT: 	t_list *list
 * OUTPUT:	void
 */
void	listdelone(t_list *list)
{
	t_lnode	*aux;

	if (list->n_elem)
	{
		aux = listpop(list);
		free(aux->mvnt);
		free(aux);
	}
}

/* function which deletes a list
 * INPUT: 	t_list **list
 * OUTPUT:	void
 */
void	listdelall(t_list *list)
{
	if (!list)
		return ;
	while (list->n_elem)
		listdelone(list);
	list->head = NULL;
	free(list);
	list = NULL;
}
