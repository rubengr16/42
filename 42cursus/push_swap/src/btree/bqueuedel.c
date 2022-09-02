/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bqueuedel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:58:42 by rgallego          #+#    #+#             */
/*   Updated: 2022/09/02 20:41:39 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

void	bqueuedelall(t_bqueue *bqueue)
{
	t_bqnode	*aux;

	if (!bqueue)
		return ;
	aux = bqueuedequeue(bqueue);
	while (aux)
	{
		free(aux->bnode);
		free(aux);
		aux = bqueuedequeue(bqueue);
	}
	bqueue->head = NULL;
	bqueue->tail = NULL;
	free(bqueue);
	bqueue = NULL;
}
