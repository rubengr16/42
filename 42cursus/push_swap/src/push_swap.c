/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:22:18 by rgallego          #+#    #+#             */
/*   Updated: 2022/08/31 16:13:39 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "queue.h"
#include "mvmnts.h"
#include "parser.h"
#include "algorithm.h"

void	printqueue(t_queue queue)
{
	t_qnode	*aux;
	int		cnt;

	cnt = 0;
	aux = queue.head;
	while (cnt < queue.n_elem)
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


	if (argc == 1)
		ft_error("Error. Enter more than 1 argument.", STDERR_FILENO, ERR_USR);
	a = queueinit();
	b = queueinit();
	if (a && b)
	{
		argtostack(a, &argv[1]);
		if (a->n_elem == 1)
			ft_error("Error. Enter more than 1 number", STDERR_FILENO, ERR_USR);
		if (a)
		{
			algorithm_prep(*a);
			//printqueue(*a);
			ft_mergesort(a, b, (a->n_elem / 2));
		}
		queuedelall(a);
		queuedelall(b);
	}
	else
		printf("Nay, bad input\n");
	//system("leaks push_swap");
	return (0);
}
