/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 09:39:43 by rgallego          #+#    #+#             */
/*   Updated: 2022/10/07 18:09:39 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"
#include <stdio.h>
#include <fcntl.h>	
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

void	think_bigger_a(t_queue *a, t_queue *b, int size_a, int size_b)
{
	while (size_a > 0 || size_b > 0)
	{
		printf("\na_size = %d, b_size = %d\n", size_a, size_b);
		if (size_a <= 0 || (size_b > 0 && (a->head->num > b->head->num)))
		{
			push(a, b);
			size_b--;
		}
		else
			size_a--;
		rotate(a);
	}
}

void	think_bigger_b(t_queue *a, t_queue *b, int size_a, int size_b)
{
	while (size_a > 0 || size_b > 0)
	{
		printf("\na_size = %d, b_size = %d\n", size_a, size_b);
		if (size_b <= 0 || (size_a > 0 && (a->head->num < b->head->num)))
		{
			push(b, a);
			size_a--;
		}
		else
			size_b--;
		rotate(b);
	}
}


// void	prints(t_stack *stack)
// {
// 	t_snode	*aux;
// 	char	c;

// 	if (!stack)
// 		return ;
// 	aux = stack->head;
// 	while (aux)
// 	{
// 		c = aux->num;
// 		write(1, &c, 1);
// 		write(1, " ", 1);
// 		aux = aux->next;
// 	}
// 	write(1, "\n---------------------------------\n", 1);
// }

void	the_algorithm(t_queue *a, t_queue *b, t_stack *a_stck)
{
	t_snode	*aux;
	int		a_size;
	int		b_size;
	int		cnt;


	cnt = 0;
	while(a_stck->head)
	{
		// prints(a_stck);
		aux = stackpop(a_stck);
		a_size = aux->num;
		free(aux);
		aux = stackpop(a_stck);
		b_size = aux->num;
		printf("\na_size = %d, b_size = %d\n", a_size, b_size);
		free(aux);
		if ((!(cnt % 2)) && a_size < 3 && b_size < 3)
			think_smaller(a, b, a_size, b_size);
		else if (a_size < 3 && b_size < 3)
			think_smaller(b, a, a_size, b_size);
		if (!(cnt % 2))
			think_bigger_a(a, b, a_size, b_size);
		else	
			think_bigger_b(a, b, b_size, a_size);
		cnt++;
	}
}
