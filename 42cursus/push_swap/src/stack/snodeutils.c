/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snodeutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:50:26 by rgallego          #+#    #+#             */
/*   Updated: 2023/02/03 00:01:47 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

t_snode	*newsnode(int min, int max)
{
	t_snode	*aux;

	aux = malloc(sizeof(t_snode));
	if (!aux)
		return (NULL);
	aux->min = min;
	aux->max = max;
	aux->size = aux->max - aux->min + 1;
	aux->next = NULL;
	return (aux);
}

void	snode_set_min(t_snode *node, int min)
{
	node->min = min;
	node->size = node->max - node->min + 1;
}

void	snode_set_max(t_snode *node, int max)
{
	node->max = max;
	node->size = node->max - node->min + 1;
}
