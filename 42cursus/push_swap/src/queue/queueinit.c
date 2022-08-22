/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queueutils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:47:23 by rgallego          #+#    #+#             */
/*   Updated: 2022/08/22 18:57:35 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

/*
 * function which reserves memory using malloc and initializes its values
 * head and n_elem to NULL and 0 respectively
 * INPUT:	t_queue *queue
 * OUTPUT:	void
 */
t_queue	*queueinit(void)
{
	t_queue	*queue;

	queue = malloc(sizeof(t_queue));
	if (queue)
	{
		queue->head = NULL;
		queue->n_elem = 0;
	}
	return (queue);
}
