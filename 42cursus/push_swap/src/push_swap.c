/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:22:18 by rgallego          #+#    #+#             */
/*   Updated: 2021/12/20 15:52:29 by rgallego         ###   ########.fr       */
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
		if (ft_setisdigit(&argv[1]))
		{
			a = ft_queueinit();
			b = ft_queueinit();
			if (a && b)
			{
				ft_argtostack(&a, &argv[1]);
				if (a)
				{
					printqueue(a);
					ft_sortbase(a, UNSORTED);
					printqueue(a);
					ft_queuedelall(&a);
				}
				if (b)
					ft_queuedelall(&b);
			}
			printf("OK\n");
		}
		else
			printf("Nay, bad input\n");
	}
	else
		printf("More arguments please\n");
	return (0);
}
