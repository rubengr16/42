/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:42:13 by rgallego          #+#    #+#             */
/*   Updated: 2021/11/21 19:03:00 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int	ft_swap_stack(t_stack *stack)
{
	t_node	*aux;

	if (stack->n_elem > 1)
	{
		/* jejeje, some problems and brainfuck */
		return (1);
	}
	else
		return (0);
}

void	ft_swap_a(t_stack *a)
{
	if (ft_swap_stack(a))
		ft_putstr_fd("sa", 1);
}

void	ft_swap_a(t_stack *b)
{
	if (ft_swap_stack(b))
		ft_putstr_fd("sb", 1);
}

void	ft_swap_ab(t_stack *a, t_stack *b)
{
	if (a->n_elem > 1 && b->n_elem > 1)
	{
		ft_swap_stack(a);
		ft_swap_stack(b);
		ft_putstr_fd("ss", 1);
	}
}
