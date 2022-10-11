/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 09:39:43 by rgallego          #+#    #+#             */
/*   Updated: 2022/10/11 20:12:29 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

void	think_smaller(t_push_swap push_swap, int a_size, int b_size)
{
	if (a_size == 2 && b_size == 2
		&& push_swap.a->head->num > push_swap.a->head->next->num
		&& push_swap.b->head->num > push_swap.b->head->next->num)
		swap_both(push_swap.a, push_swap.b, push_swap.mvnts);
	else if (a_size == 2
		&& push_swap.a->head->num > push_swap.a->head->next->num)
		swap(push_swap.a, push_swap.mvnts);
	else if (b_size == 2
		&& push_swap.b->head->num > push_swap.b->head->next->num)
		swap(push_swap.b, push_swap.mvnts);
}

void	think_bigger_a(t_push_swap push_swap, int size_a, int size_b)
{
	while (size_a > 0 || size_b > 0)
	{
		if (size_a <= 0
			|| (size_b > 0
			&& (push_swap.a->head->num > push_swap.b->head->num)))
		{
			push(push_swap.a, push_swap.b, push_swap.mvnts);
			size_b--;
		}
		else
			size_a--;
		rotate(push_swap.a, push_swap.mvnts);
	}
}

void	think_bigger_b(t_push_swap push_swap, int size_a, int size_b)
{
	while (size_a > 0 || size_b > 0)
	{
		if (size_b <= 0
			|| (size_a > 0
			&& (push_swap.a->head->num < push_swap.b->head->num)))
		{
			push(push_swap.b, push_swap.a, push_swap.mvnts);
			size_a--;
		}
		else
			size_b--;
		rotate(push_swap.b, push_swap.mvnts);
	}
}

void	the_algorithm(t_push_swap push_swap, t_stack *a_stck)
{
	t_snode	*aux;
	int		a_size;
	int		b_size;
	int		cnt;


	cnt = 0;
	while(a_stck->head)
	{
		aux = stackpop(a_stck);
		a_size = aux->num;
		free(aux);
		aux = stackpop(a_stck);
		b_size = aux->num;
		free(aux);
		if ((!(cnt % 2)) && a_size < 3 && b_size < 3)
			think_smaller(push_swap, a_size, b_size);
		else if (a_size < 3 && b_size < 3)
			think_smaller(push_swap, a_size, b_size);
		if (!(cnt % 2))
			think_bigger_a(push_swap, a_size, b_size);
		else
			think_bigger_b(push_swap, a_size, b_size);
		cnt++;
	}
}
