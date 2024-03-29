/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackpush.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 20:42:42 by rgallego          #+#    #+#             */
/*   Updated: 2023/02/02 19:00:05 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

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
