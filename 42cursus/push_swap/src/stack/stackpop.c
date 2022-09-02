/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackpop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 20:43:06 by rgallego          #+#    #+#             */
/*   Updated: 2022/09/02 17:41:57 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_snode	*stackpop(t_stack *stack)
{
	t_snode	*aux;

	if (!stack->head)
		return (NULL);
	aux = stack->head;
	stack->head = stack->head->next;
	aux->next = NULL;
	return (aux);
}
