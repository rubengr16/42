/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackdel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 20:43:57 by rgallego          #+#    #+#             */
/*   Updated: 2023/02/01 17:45:02 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stackdelall(t_stack *stack)
{
	t_snode	*aux;

	if (!stack)
		return ;
	aux = stackpop(stack);
	while (aux)
	{
		free(aux);
		aux = stackpop(stack);
	}
	stack->head = NULL;
	free(stack);
	stack = NULL;
}
