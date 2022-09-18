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
#include <stdio.h>
void	think_smaller(t_queue *a, t_queue *b, int a_size, int b_size)
{
	if (a_size == 2 && b_size == 2 && a->head->num > a->head->next->num
		&& b->head->num > b->head->next->num)
		swap_both(a, b);
	else if (a_size == 2 && a->head->num > a->head->next->num)
		swap(a);
	else if (b_size == 2 && b->head->num > b->head->next->num)
		swap(b);
}

void	think_bigger(t_queue *q1, t_queue *q2, int size1, int size2)
{
	while (size1 > 0 || size2 > 0)
	{
		if (size1 <= 0 || (size2 > 0 && (q1->head->num > q2->head->num)))
		{
			push(q1, q2);
			size2--;
		}
		else
			size1--;
		rotate(q1);
	}
}

void	the_algorithm(t_queue *a, t_queue *b, t_stack *a_stck)
{
	t_snode	*aux;
	int		a_size;
	int		b_size;
	int		cnt;

	cnt = 0;
	while(a_stck->head)
	{
		aux = stackpop(a_stck);
		b_size = aux->num;
		free(aux);
		aux = stackpop(a_stck);
		a_size = aux->num;
		free(aux);
		if ((!(cnt % 2)) && a_size < 3 && b_size < 3)
			think_smaller(a, b, a_size, b_size);
		else if (a_size < 3 && b_size < 3)
			think_smaller(b, a, a_size, b_size);
		if (!(cnt % 2))
			think_bigger(a, b, a_size, b_size);
		else	
			think_bigger(b, a, a_size, b_size);
		cnt++;
	}
}
