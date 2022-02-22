/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decisions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:21:15 by rgallego          #+#    #+#             */
/*   Updated: 2021/12/20 17:35:00 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

/*
 * 
 * INPUT:	
 * OUTPUT:	
 */
int	ft_n_rot(t_queue *queue, int avg)
{
	int		n_rot;
	t_node	*aux;

	n_rot = 0;
	if (queue->head->num > avg)
	{
		aux = queue->head->next;
		n_rot++;
		while (aux != queue->head && aux->num > avg)
		{
			aux = aux->next;
			n_rot++;
		}
	}
	return (n_rot);
}

/*
 * 
 * INPUT:	
 * OUTPUT:	
 */
int	ft_n_revrot(t_queue	*queue, int avg)
{
	int		n_revrot;
	t_node	*aux;

	n_revrot = 0;
	if (queue->head->num > avg)
	{
		aux = queue->head->prvs;
		n_revrot++;
		while (aux != queue->head && aux->num > avg)
		{
			aux = aux->prvs;
			n_revrot++;
		}
	}
	return (n_revrot);
}

/*
 * 
 * INPUT:	
 * OUTPUT:	
 */
void	ft_rotpush(t_queue *a, t_queue *b, int avg, int lvl)
{
	while (a->head->num > avg)
		ft_rotate_a(a);
	a->head->state = lvl;
	ft_push_b(a, b);
	if (b->head->next > b->head)
		ft_swap_b(b);
}

/*
 * 
 * INPUT:	
 * OUTPUT:	
 */
void	ft_revrotpush(t_queue *a, t_queue *b, int avg, int lvl)
{
	while (a->head->num > avg)
		ft_reverse_rotate_a(a);
	a->head->state = lvl;
	ft_push_b(a, b);
	if (b->head->next > b->head)
		ft_swap_b(b);
}
