/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:22:18 by rgallego          #+#    #+#             */
/*   Updated: 2021/12/02 14:46:47 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "queue.h"
#include "mvmnts.h"

/*
 * TEST FOR MY QUEUE
 */

int	main(void)
{
	t_queue *my_queue;
	t_queue	*my_b_queue;
	t_node	*my_node;
	int		i;

	my_queue = malloc(sizeof(t_queue));
	my_b_queue = malloc(sizeof(t_queue));
	i = 0;
	while (i < 100)
	{
		ft_queueadd_front_num(i, my_queue);
		i++;
	}
	i = 0;
	my_node = my_queue->head;
	printf("\n****************** ORDERED ********************\n");
	while (i < 100)
	{
		printf("Elemento %d: %d\n", i, my_node->num);
		my_node = my_node->next;
		i++;
	}

	printf("\n****************** sa ********************\n");
	ft_swap_a(my_queue);
	i = 0;
	my_node = my_queue->head;
	while (i < 100)
	{
		printf("Elemento %d: %d\n", i, my_node->num);
		my_node = my_node->next;
		i++;
	}

	printf("\n****************** ra ********************\n");
	ft_rotate_a(my_queue);
	i = 0;
	my_node = my_queue->head;
	while (i < 100)
	{
		printf("Elemento %d: %d\n", i, my_node->num);
		my_node = my_node->next;
		i++;
	}

	printf("\n****************** rra ********************\n");
	ft_reverse_rotate_a(my_queue);
	i = 0;
	my_node = my_queue->head;
	while (i < 100)
	{
		printf("Elemento %d: %d\n", i, my_node->num);
		my_node = my_node->next;
		i++;
	}

	printf("\n****************** pb ********************\n");
	ft_push_b(my_b_queue, my_queue);
	i = 0;
	my_node = my_queue->head;
	while (i < 99)
	{
		printf("Elemento %d: %d\n", i, my_node->num);
		my_node = my_node->next;
		i++;
	}
	i = 0;
	printf("my_b_queue->n_elem = %d", my_b_queue->n_elem);
	while (my_b_queue->n_elem)
	{
		printf("Elemento %d: %d\n", i, ft_queuepop(my_b_queue)->num);
		printf("n_elem: %d", my_b_queue->n_elem
		i++;
	}
	printf("HOLE");
	/*
	while (my_queue->head)
	{
		printf("Elemento %d: %d\n", i, my_queue->head->num);
		ft_queuedelone(my_queue);
		i++;
	*/
	ft_queuedelall(my_queue);
//	system("leaks a.out");
	return (0);
}
