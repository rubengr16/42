/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugonzal <jugonzal@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 14:37:05 by jugonzal          #+#    #+#             */
/*   Updated: 2021/08/22 14:39:13 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct.h"

void	ft_init(t_list *list)
{
	list = malloc(sizeof(t_list));
	list->head = NULL;
	list->tail = NULL;
}

int	ft_empty(t_list *list)
{
	return (!list);
}

void	ft_insert(t_list *list, char *id, char *nb_str, int size)
{
	t_node	*aux;

	aux = (t_node *)malloc(sizeof(t_node));
	if (aux)
	{
		aux->id = id;
		aux->nb_str = nb_str;
		aux->size = size;
		aux->next = NULL;
		if (ft_empty(list))
		{	
			list->head = aux;
		}
		else
			list->tail->next = aux;
		list->tail = aux;
	}
}

char	*ft_search_bigger(t_list *list, int size)
{
	t_node	*aux;

	aux = list->head;
	while (aux && aux->size != size)
		aux = aux->next;
	return (aux->nb_str);
}

char	*ft_search_little(t_list *list, char id, int size)
{
	t_node	*aux;

	aux = list->head;
	while (aux && *(aux->id) != id && aux->size != size)
		aux = aux->next;
	return (aux->nb_str);
}
