/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:42:13 by rgallego          #+#    #+#             */
/*   Updated: 2021/11/20 18:14:14 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	ft_swap_a(t_stack *a)
{
	int	aux;

	if (a->n_elem > 1)
	{
		aux = a->stack->num;
		a->stack->num = a->stack->next->num;
		a->stack->next->num = aux;
		ft_putstr_fd("sa", 1);
	}
}


void	ft_swap_a(t_stack *b)
{
	int	aux;

	if (b->n_elem > 1)
	{
		aux = b->stack->num;
		b->stack->num = b->stack->next->num;
		b->stack->next->num = aux;
		ft_putstr_fd("sb", 1);
	}
}

void	ft_swap_ab(t_stack *a, t_stack *b)
{
	int	aux;

	if (a->elem > 1 && b->elem > 1)
	{
		aux = a->stack->num;
		a->stack->num = a->stack->next->num;
		a->stack->next->num = aux;
		aux = b->stack->num;
		b->stack->num = b->stack->next->num;
		b->stack->next->num = aux;
		ft_putstr_fd("ss", 1);
	}
}
