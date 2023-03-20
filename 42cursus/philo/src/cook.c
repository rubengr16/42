/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 23:29:48 by rgallego          #+#    #+#             */
/*   Updated: 2023/03/20 23:42:49 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	waiter(t_philo *philo)
{
	t_philo_n		*aux;
	struct timeval	now;
	unsigned int	n_finished;

	aux = philo->philos.head;
	n_finished = 0;
	while (is_death(&philo->apoptosis, READ) != DIE
		&& (!philo->needed_dines || n_finished < philo->n_philos))
	{
		gettimeofday(&now, NULL);
		if (getutimediff(aux->last_sup_time, now) >= philo->v_func.time[THINK])
		{
			is_death(&philo->apoptosis, DIE);
			talk(aux, DIE, DIE_MSG);
		}
		if (aux->n_dines == *aux->needed_dines)
			n_finished++;
		aux = aux->next;
	}
}

void	set_the_table(t_philo *philo)
{
	unsigned int	cnt;

	pthread_mutex_init(&philo->apoptosis.mutex, NULL);
	pthread_mutex_init(&philo->printf_mutex, NULL);
	cnt = 0;
	while (cnt < philo->n_philos)
	{
		pthread_create(&philo->philos.head->thread, NULL, philosophare,
			philo->philos.head);
		philo->philos.head = philo->philos.head->next;
		cnt++;
	}
	waiter(philo);
	cnt = 0;
	while (cnt < philo->n_philos)
	{
		pthread_join(philo->philos.head->thread, NULL);
		philo->philos.head = philo->philos.head->next;
		cnt++;
	}
}
