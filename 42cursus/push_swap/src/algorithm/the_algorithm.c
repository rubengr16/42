/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 09:39:43 by rgallego          #+#    #+#             */
/*   Updated: 2022/09/02 13:42:05 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

void	think_smaller(t_queue *a, t_queue *b, int a_size, int b_size)
{
	if (a_size == 2 && b_size == 2 && a->head->num > a->head->next->num
		&& b->head->num < b->head->next->num)
		swap_both(a, b);
	else if (a_size == 2 && a->head->num > a->head->next->num)
		swap(a);
	else if (b_size == 2 && b->head->num < b->head->next->num)
		swap(b);
	while (a_size > 0 || b_size > 0)
	{
		if (b_size > 0 && a_size > 0)
			rotate_both(a, b);
		else if (a_size > 0)
			rotate(a);
		else if (b_size > 0)
			rotate(b);
		a_size--;
		b_size--;
	}
}

void	the_algorithm(t_queue *a, t_queue *b, t_stack *a_stck, t_stack *b_stck)
{
	t_snode	*aux;
	int		a_size;
	int		b_size;

	while(a_stck->head->num <= 2 && b_stck->head->num <= 2)
	{
		aux = stackpop(a_stck);
		a_size = aux->num;
		free(aux);
		aux = stackpop(b_stck);
		b_size = aux->num;
		free(aux);
		if(a_size < 3 && b_size < 3)
			think_smaller(a, b, a_size, b_size);
		// else
		// 	think_bigger(a, b, a_size, b_size);
	}
}
