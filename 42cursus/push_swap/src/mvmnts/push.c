/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:27:40 by rgallego          #+#    #+#             */
/*   Updated: 2022/10/11 15:32:50 by rgallego         ###   ########.fr       */
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
void	push(t_queue *dst, t_queue *src, t_list *mvnts)
{
	char	*mvnt_name;

	if (!push_queue(dst, src))
		return ;
	mvnt_name = malloc(sizeof(char) * 3);
	mvnt_name[0] = 'p';
	mvnt_name[1] = dst->id;
	mvnt_name[2] = '\0';
	listadd_back_mvnt(mvnts, mvnt_name);
}
