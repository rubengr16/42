/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:27:40 by rgallego          #+#    #+#             */
/*   Updated: 2022/09/01 10:13:50 by rgallego         ###   ########.fr       */
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
static int	push_queue(t_queue *dst, t_queue *src)
{
	if (src->n_elem)
	{
		queueadd_front(dst, queuepop(src));
		return (1);
	}
	else
		return (0);
}

/*
 * function which moves the first element of dst to insert it as the first one
 * of src
 * INPUT:	t_queue *dst, t_queue *src
 * OUTPUT:	void
 */
void	push(t_queue *dst, t_queue *src)
{
	if (!push_queue(dst, src))
		return ;
	ft_putchar_fd('p', STDOUT_FILENO);
	ft_putchar_fd(dst->id, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}
