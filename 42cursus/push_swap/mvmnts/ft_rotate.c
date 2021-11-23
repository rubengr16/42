/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:04:21 by rgallego          #+#    #+#             */
/*   Updated: 2021/11/23 12:15:45 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	ft_rotate_stack(t_stack *stack)
{
	if (stack->n_elem > 1)
		stack->head = stack->head->next;
}

void	ft_rotate_a(t_stack *a)
{
	ft_rotate_stack(a);
	ft_putstr_fd("ra", 1);
}

void	ft_rotate_b(t_stack *b)
{
	ft_rotate_stack(a);
	ft_putstr_fd("rb", 1);
}

void	ft_rotate_ab(t_stack *a, t_stack *b)
{
	ft_rotate_stack(a);
	ft_rotate_stack(b);
	ft_putstr_fd("rr", 1);
}
