/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:22:18 by rgallego          #+#    #+#             */
/*   Updated: 2021/12/13 00:14:24 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "queue.h"
#include "mvmnts.h"
#include "parser.h"

int	main(int argc, char **argv)
{
	t_queue	*a;
	t_queue	*b;
	//t_node	*aux;
	//int		cnt;

	if (argc > 1)
	{
		if (ft_setisdigit(&argv[1]))
		{
			a = ft_queueinit();
			b = ft_queueinit();
			if (a && b)
			{
				ft_argtostack(a, &argv[1]);
				printf("\n%d", a->head->num);
		/*		if (a)
				{
					cnt = 0;
					aux = a->head;
					while (cnt < a->n_elem)
					{
						printf("Elem %d: %d\n", cnt, aux->num);
						aux = aux->next;
						cnt++;
					}
					//ft_queuedelall(a);
				}*/
				//if (a)
				//	ft_queuedelall(a);
				if (b)
					ft_queuedelall(b);
			}
		}
		else
			printf("Nay, bad input\n");
	}
	else
		printf("More arguments please\n");
	return (0);
}
