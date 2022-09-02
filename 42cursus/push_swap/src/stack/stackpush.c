/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackpush.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 20:42:42 by rgallego          #+#    #+#             */
/*   Updated: 2022/09/02 17:42:31 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_snode	*newsnode(int num)
{
	t_snode	*aux;

	aux = malloc(sizeof(t_snode));
	if (!aux)
		return (NULL);
	aux->num = num;
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

t_snode	*stackpush_num(t_stack *stack, int num)
{
	t_snode	*aux;

	aux = newsnode(num);
	if (!aux)
		return (NULL);
	stackpush(stack, aux);
	return (aux);
}
