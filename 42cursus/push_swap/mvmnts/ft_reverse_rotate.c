/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:17:16 by rgallego          #+#    #+#             */
/*   Updated: 2021/11/23 18:22:21 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_reverse_rotate_queue(t_queue *queue)
{
	if (queue->n_elem > 1)
	{
		queue->head = queue->head->prvs;
		return (1);
	}
	else
		return (0);
}

void	ft_reverse_rotate_a(t_queue *a)
{
	if (ft_reverse_rotate_queue(a))
		ft_putstr_fd("rra", 1);
}

void	ft_reverse_rotate_b(t_queue *b)
{
	if (ft_reverse_rotate_queue(a))
		ft_putstr_fd("rrb", 1);
}

void	ft_reverse_rotate_ab(t_queue *a, t_queue *b)
{
	if (ft_reverse_rotate_queue(a))
	{
		if (ft_reverse_rotate_queue(b))
			ft_putstr_fd("rrr", 1);
		else
			ft_rotate_queue(a);
}
