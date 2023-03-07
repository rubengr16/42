/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_queue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 19:59:36 by rgallego          #+#    #+#             */
/*   Updated: 2023/03/07 21:03:14 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	push_philo(t_philo_q *queue, t_philo_n	*node)
{
	if (!node)
		return (-1);
	if (!queue->n_philos)
	{
		queue->head = node;
		node->next = node;
		node->prvs = node;
	}
	else if (queue->n_philos == 1)
	{
		queue->head->next = node;
		queue->head->prvs = node;
		node->next = queue->head;
		node->prvs = queue->head;
	}
	else if (queue->n_philos > 1)
	{
		node->prvs = queue->head->prvs;
		node->next = queue->head;
		node->next->prvs = node;
		node->prvs->next = node;
	}
	return (0);
}

int	philo_sire(t_philo *philo, t_philo_q *q, unsigned int n)
{
	t_philo_n	*node;

	gettimeofday(&philo->start_time, NULL);
	while (q->n_philos < n)
	{
		node = malloc(sizeof(t_philo_n));
		if (!node || push_philo(q, node) < 0)
			return (-1);
		q->n_philos++;
		node->id = q->n_philos;
		node->n_dines = 0;
		node->needed_dines = &philo->needed_dines;
		node->status = THINK;
		node->status_msg = NULL;
		node->v_func = &philo->v_func;
		node->apoptosis = &philo->apoptosis;
		node->updated_time = philo->start_time;
		node->birth_time = &philo->start_time;
		node->chopstick.value = FREE;
		pthread_mutex_init(&node->chopstick.rw_lock, NULL);
		node->printf_mutex = &philo->printf_mutex;
	}
	return (0);
}

t_philo_n	*philo_pop(t_philo_q *queue)
{
	t_philo_n	*aux;

	aux = queue->head;
	if (queue->n_philos == 1)
		queue->head = NULL;
	else if (queue->n_philos > 1)
	{
		if (queue->n_philos == 2)
		{
			aux->next->prvs = aux->next;
			aux->prvs->next = aux->prvs;
		}
		else
		{
			aux->next->prvs = aux->prvs;
			aux->prvs->next = aux->next;
		}
		queue->head = queue->head->next;
		aux->next = NULL;
		aux->prvs = NULL;
	}
	if (queue->n_philos)
		queue->n_philos--;
	return (aux);
}

void	philo_killer(t_philo_q *queue)
{
	t_philo_n	*philo;

	if (!queue)
		return ;
	while (queue->n_philos)
	{
		philo = philo_pop(queue);
		if (philo)
		{
			pthread_mutex_destroy(&philo->chopstick.rw_lock);
			free(philo);
		}
	}
	pthread_mutex_destroy(&philo->apoptosis->rw_lock);
	pthread_mutex_destroy(philo->printf_mutex);
	queue->head = NULL;
}
