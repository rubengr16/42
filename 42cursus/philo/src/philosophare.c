/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophare.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:40:25 by rgallego          #+#    #+#             */
/*   Updated: 2023/02/25 18:40:32 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	talk(t_philo_n *philo, int status, char *msg)
{
	struct timeval	now;
	unsigned long	time;

	gettimeofday(&now, NULL);
	time = getutimediff(*philo->birth_time, now);
	if (!msg)
	{
		msg = philo->v_func->status[status];
		philo->status = status;
	}
	pthread_mutex_lock(philo->printf_mutex);
	printf("%ld %u %s\n", time / US_MS, philo->id, msg);
	pthread_mutex_unlock(philo->printf_mutex);
}

void	live(t_philo_n *philo, int *chopstick, unsigned long time)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	if (!chopstick)
		philo->updated_time = now;
	// printf("hola\n");
	while (!*philo->apoptosis && getutimediff(philo->updated_time, now) < (time * US_MS)
		&& (!chopstick || *chopstick == BUSY))
		gettimeofday(&now, NULL);
	if (philo->status == EAT)
		philo->n_dines++;
}

void	*philosophare(void *varg)
{
	t_philo_n	*philo;

	philo = (t_philo_n *)varg;
	while(!*philo->apoptosis && (!*philo->needed_dines
		|| *philo->needed_dines <= philo->n_dines))
	{
		if (philo->chopstick == BUSY)
			live(philo, &philo->chopstick, philo->v_func->time[THINK]);
		pthread_mutex_lock(&philo->mutex);
		philo->chopstick = BUSY;
		talk(philo, -1, TAKE_MSG);
		if (philo->next->chopstick == BUSY)
			live(philo, &philo->next->chopstick, philo->v_func->time[THINK]);
		pthread_mutex_lock(&philo->next->mutex);
		philo->next->chopstick = BUSY;
		talk(philo, -1, TAKE_MSG);
		talk(philo, EAT, NULL);
		live(philo, NULL, philo->v_func->time[EAT]);
		philo->chopstick = FREE;
		pthread_mutex_unlock(&philo->mutex);
		philo->next->chopstick = FREE;
		pthread_mutex_unlock(&philo->next->mutex);
		talk(philo, SLEEP, NULL);
		live(philo, NULL, philo->v_func->time[SLEEP]);
		talk(philo, THINK, NULL);
	}
	return (NULL);
}


void	*lastphilosophare(void *varg)
{
	t_philo_n	*philo;

	philo = (t_philo_n *)varg;
	while(!*philo->apoptosis && (!*philo->needed_dines
		|| *philo->needed_dines <= philo->n_dines))
	{
		if (philo->next->chopstick == BUSY)
			live(philo, &philo->next->chopstick, philo->v_func->time[THINK]);
		pthread_mutex_lock(&philo->next->mutex);
		philo->next->chopstick = BUSY;
		talk(philo, -1, TAKE_MSG);
		if (philo->chopstick == BUSY)
			live(philo, &philo->chopstick, philo->v_func->time[THINK]);
		pthread_mutex_lock(&philo->mutex);
		philo->chopstick = BUSY;
		talk(philo, -1, TAKE_MSG);
		talk(philo, EAT, NULL);
		live(philo, NULL, philo->v_func->time[EAT]);
		philo->next->chopstick = FREE;
		pthread_mutex_unlock(&philo->next->mutex);
		philo->chopstick = FREE;
		pthread_mutex_unlock(&philo->mutex);
		talk(philo, SLEEP, NULL);
		live(philo, NULL, philo->v_func->time[SLEEP]);
		talk(philo, THINK, NULL);
	}
	return (NULL);
}

void	set_the_table(t_philo *philo)
{
	unsigned int	cnt;

	cnt = 1;
	while(cnt < philo->n_philos)
	{
		pthread_create(&philo->philos.head->thread, NULL, philosophare,
			philo->philos.head);
		philo->philos.head = philo->philos.head->next;
		cnt++;
	}
	pthread_create(&philo->philos.head->thread, NULL, lastphilosophare,
		philo->philos.head);
	cnt = 0;
	philo->philos.head = philo->philos.head->next;
	while (cnt < philo->n_philos)
	{
		pthread_join(philo->philos.head->thread, NULL);
		philo->philos.head = philo->philos.head->next;
		cnt++;
	}
}
