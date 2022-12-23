/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackpush.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 20:42:42 by rgallego          #+#    #+#             */
/*   Updated: 2022/12/23 16:41:54 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_snode	*newsnode(int min, int max)
{
	t_snode	*aux;

	aux = malloc(sizeof(t_snode));
	if (!aux)
		return (NULL);
	aux->min = min;
	aux->max = max;
	aux->next = NULL;
	return (aux);
}

void	stackpush(t_stack *stack, t_snode *node)
{
	if (!node)
		return ;
	node->next = stack->head;
	stack->head = node;
}

t_snode	*stackpush_minmax(t_stack *stack, int min, int max)
{
	t_snode	*aux;

	aux = newsnode(min, max);
	if (!aux)
		return (NULL);
	stackpush(stack, aux);
	return (aux);
}
