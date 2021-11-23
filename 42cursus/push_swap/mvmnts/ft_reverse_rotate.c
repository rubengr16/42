/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:17:16 by rgallego          #+#    #+#             */
/*   Updated: 2021/11/23 12:15:44 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	ft_reverse_rotate_stack(t_stack *stack)
{
	if (stack->n_elem > 1)
		stack->head = stack->head->prvs;
}

void	ft_reverse_rotate_a(t_stack *a)
{
	ft_reverse_rotate_stack(a);
	ft_putstr_fd("rra", 1);
}

void	ft_reverse_rotate_b(t_stack *b)
{
	ft_reverse_rotate_stack(a);
	ft_putstr_fd("rrb", 1);
}

void	ft_reverse_rotate_ab(t_stack *a, t_stack *b)
{
	ft_reverse_rotate_stack(a);
	ft_reverse_rotate_stack(b);
	ft_putstr_fd("rrr", 1);
}
