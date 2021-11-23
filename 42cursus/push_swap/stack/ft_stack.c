/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:32:30 by rgallego          #+#    #+#             */
/*   Updated: 2021/11/23 12:15:03 by rgallego         ###   ########.fr       */
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
	t_node	*aux;

	aux = stack->head;
	if (stack->n_elem == 1)
		stack->head = NULL;
	else if (stack->n_elem > 1)
	{
		if (stack->n_elem == 2)
		{
			aux->next->prvs = NULL;
			aux->prvs->next = NULL;
		}
		else
		{
			aux->next->prvs = aux->prvs;
			aux->prvs->next = aux->next;
		}
		stack->head = stack->head->next;
		aux->next = NULL;
		aux->prvs = NULL;
	}
	return (aux);
}

/*
 * function which inserts a node received as argument into a stack
 * INPUT:	t_node *node, t_stack *stack
 * OUTPUT:	void
 */
void	ft_stckadd(t_node *node, t_stack *stack)
{
	if (stack->n_elem == 1)
	{
		stack->head->next = node;
		stack->head->prvs = node;
		node->next = stack->head;
		node->prvs = stack->head;
	}
	else if (stack->n_elem > 1)
	{
		node->prvs = stack->head->prvs;	
		node->next = stack->head;
		node->next->prvs = node;
		node->prvs->next = node;
	}
	stack->head = node;
	stack->elem++;
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
