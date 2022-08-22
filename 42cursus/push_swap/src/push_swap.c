/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:22:18 by rgallego          #+#    #+#             */
/*   Updated: 2022/08/22 20:54:57 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "queue.h"
#include "mvmnts.h"
#include "parser.h"
#include "algorithm.h"

void	printqueue(t_queue *queue)
{
	t_node	*aux;
	int		cnt;

	cnt = 0;
	aux = queue->head;
	while (cnt < queue->n_elem)
	{
		printf("Elem %d: %d\n", cnt, aux->num);
		aux = aux->next;
		cnt++;
	}
}

int	main(int argc, char **argv)
{
	t_queue	*a;
	t_queue	*b;


	if (argc > 1)
	{
		if (ft_setisnumber(&argv[1]))
		{
			a = queueinit();
			b = queueinit();
			if (a && b)
			{
				argtostack(&a, &argv[1]);
				if (a)
				{
					printqueue(a);
					t_vector *v = merge_sort(*a);
					for (int i = 0; i < v->n_elem; i++)
						printf("%d\n", v->nums[i]);
					queuedelall(&a);
				}
				if (b)
					queuedelall(&b);
			}
		}	
		else
			printf("Nay, bad input\n");
	}
	else
		printf("More arguments please\n");
	return (0);
}
