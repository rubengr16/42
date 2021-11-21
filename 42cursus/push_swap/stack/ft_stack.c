/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:32:30 by rgallego          #+#    #+#             */
/*   Updated: 2021/11/21 20:23:43 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
 * function which deletes one node from a stack and returns it
 * INPUT:	t_stack *stack
 * OUTPUT:	t_node		:	deleted node with its next and previous pointers
 * 							set to NULL
 */
t_node	ft_stckpop(t_stack *stack)
{
	t_node	aux;

	if (stack->n_elem)
	{
		aux = stack->head;
		aux->next->prvs = aux->prvs;
		aux->prvs->next = aux-next;
		stack->head = aux->next;
		stack->n_elem--;
		aux->next = NULL;
		aux->prvs = NULL;
		return (aux);
	}
	else
		return (NULL);
}

/*
 * function which inserts a node received as argument into a stack
 * INPUT:	t_node *node, t_stack *stack
 * OUTPUT:	void
 */
void	ft_stckadd(t_node *node, t_stack *stack)
{
	if (stack->n_elem)
	{
		node->prvs = stack->head->prvs;	
		node->next = stack->head;
		stack->head = node;
		stack->head->next->prvs = node;
		stack->head->prvs->next = node;
	}
	else
		stack->head = node;
}

/*
 * function which creates a node with the received number as argument into a
 * stack
 * INPUT:	int num, t_stack *stack
 * OUTPUT:	void
 */
void	ft_stckadd_num(int num, t_stack *stack)
{
	t_node	*aux;

	aux = malloc(sizeof(t_node));
	aux->num = num;
	ft_stckadd(aux, stack);
}

/* function which deletes the first node of a stack
 * INPUT: 	t_stack *stack
 * OUTPUT:	void
 */
void	ft_stckdelone(t_stack *stack)
{
	t_node	*aux;
	if (stack->n_elem)
	{
		free(ft_stckpop(stack));
		stack->n_elem--;
	}
}

/* function which deletes a stack
 * INPUT: 	t_stack *stack
 * OUTPUT:	void
 */
void	ft_stckdelall(t_stack *stack)
{
	while (stack->n_elem)
		ft_stckdelone(stack);
	stack->head = NULL;
	free(stack);
}
