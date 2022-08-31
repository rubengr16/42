/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackinit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 10:14:38 by rgallego          #+#    #+#             */
/*   Updated: 2022/08/31 16:11:25 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/*
 * reserves memory using malloc and initializes its value head to NULL
 * INPUT:	void
 * OUTPUT:	t_stack *stack
 */
t_stack	*stackinit(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	return (stack);
}

/*
 * reserves memory using malloc and initializes its value head to the given
 * snode
 * INPUT:	t_snode	*snode
 * OUTPUT:	t_stack	*stack
 */
t_stack	*stackinitnode(t_snode	*snode)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = snode;
	return (stack);
}

/*
 * reserves memory using malloc and initializes its value head with a node
 * created with the given num
 * INPUT:	int		num
 * OUTPUT:	t_stack	*stack
 */
t_stack	*stackinitnum(int num)
{
	t_stack	*stack;
	t_snode	*snode;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	snode = newsnode(num);
	stack->head = snode;
	return (stack);
}
