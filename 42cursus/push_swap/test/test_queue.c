/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:22:18 by rgallego          #+#    #+#             */
/*   Updated: 2021/11/23 17:56:11 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "queue.h"

/*
 * TEST FOR MY QUEUE
 */

int	main(void)
{
	t_queue *my_queue;
	int		i;

	my_queue = malloc(sizeof(t_queue));
	i = 0;
	while (i < 100)
	{
		ft_queueadd_front_num(i, my_queue);
		i++;
	}
	i = 0;
	/*	
	while (i < 100)
	{
		printf("Elemento %d: %d\n", i, ft_queuepop(my_queue)->num);
		i++;
	}
	*/
	/*
	while (my_queue->head)
	{
		printf("Elemento %d: %d\n", i, my_queue->head->num);
		ft_queuedelone(my_queue);
		i++;
	}
	*/
	ft_queuedelall(my_queue);
	system("leaks a.out");
	return (0);
}
