/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:22:18 by rgallego          #+#    #+#             */
/*   Updated: 2021/12/03 20:35:50 by rgallego         ###   ########.fr       */
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

	my_queue = ft_queueinit();
	my_b_queue = ft_queueinit();
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
		printf("Elemento %p: %d\n", my_node, my_node->num);
		my_node = my_node->next;
		i++;
	}
/*
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
*/
	printf("\n****************** pb ********************\n");
	ft_push_b(my_b_queue, my_queue);
	i = 0;
	my_node = my_queue->head;
	while (i < 99)
	{
		printf("Elemento %p: %d\n", my_node, my_node->num);
		my_node = my_node->next;
		i++;
	}
	i = 0;
	printf("my_b_queue->n_elem = %d, dir = %p\n", my_b_queue->n_elem, my_b_queue->head);
	printf("%p\n", my_b_queue->head);
	while (my_b_queue->n_elem)
	{
 		my_node = ft_queuepop(my_b_queue);
		printf("Elemento %d: %d\n", i, my_node->num);
		i++;
	}
	free(my_node);
	i = 0;
	printf("%p\n", my_b_queue->head);
 	while (my_b_queue->n_elem)
	{
		printf("Elemento %d: %d\n", i, my_b_queue->head->num);
		ft_queuedelone(my_b_queue);
		i++;
	}
	i = 0;
 	while (my_queue->n_elem)
	{
		printf("Elemento %d: %d\n", i, my_queue->head->num);
		ft_queuedelone(my_queue);
		i++;
	}
	ft_queuedelall(my_queue);
	printf("%p\n", my_queue->head);
	printf("%p\n", my_b_queue->head);
	ft_queuedelall(my_b_queue);
	printf("%p\n", my_b_queue->head);
	system("leaks push_swap");
	return (0);
}
