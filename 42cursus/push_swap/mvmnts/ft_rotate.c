/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:04:21 by rgallego          #+#    #+#             */
/*   Updated: 2021/11/23 18:22:24 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_rotate_queue(t_queue *queue)
{
	if (queue->n_elem > 1)
	{
		queue->head = queue->head->next;
		return (1);
	}
	else
		return (0);
}

void	ft_rotate_a(t_queue *a)
{
	if (ft_rotate_queue(a))
		ft_putstr_fd("ra", 1);
}

void	ft_rotate_b(t_queue *b)
{
	if (ft_rotate_queue(a))
		ft_putstr_fd("rb", 1);
}

void	ft_rotate_ab(t_queue *a, t_queue *b)
{
	if (ft_rotate_queue(a))
	{
		if (ft_rotate_queue(b))
			ft_putstr_fd("rr", 1);
		else
			ft_reverse_rotate_queue(a);
	}
}
