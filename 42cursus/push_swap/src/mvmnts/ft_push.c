/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:27:40 by rgallego          #+#    #+#             */
/*   Updated: 2022/08/11 16:32:15 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mvmnts.h"

/*
 * function which moves the first element of src to insert it as the first one
 * of dest
 * INPUT:	t_queue *dst, t_queue *src
 * OUTPUT:	int	:	1	push is fullfilled
 * 					0	push has failed
 */
static int	ft_push_queue(t_queue *dst, t_queue *src)
{
	if (src->n_elem)
	{
		ft_queueadd_front(dst, ft_queuepop(src));
		return (1);
	}
	else
		return (0);
}

/*
 * function which moves the first element of b to insert it as the first one
 * of a
 * INPUT:	t_queue *a, t_queue *b
 * OUTPUT:	void
 */
void	ft_push_a(t_queue *a, t_queue *b)
{
	if (ft_push_queue(a, b))
		ft_putendl_fd("pa", 1);
}

/*
 * function which moves the first element of a to insert it as the first one
 * of b
 * INPUT:	t_queue *a, t_queue *b
 * OUTPUT:	void
 */
void	ft_push_b(t_queue *a, t_queue *b)
{
	if (ft_push_queue(b, a))
		ft_putendl_fd("pb", 1);
}
