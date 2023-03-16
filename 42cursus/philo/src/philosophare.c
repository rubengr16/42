/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophare.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:40:25 by rgallego          #+#    #+#             */
/*   Updated: 2023/03/16 20:30:12 by rgallego         ###   ########.fr       */
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
	printf("%ld %u %s\n", time, philo->id, msg);
	pthread_mutex_unlock(philo->printf_mutex);
}

void	live(t_philo_n *philo, unsigned long time)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	while (rw_value(philo->apoptosis, READ) != DIE
		&& getutimediff(philo->updated_time, now) < time)
	{
		usleep(100);
		gettimeofday(&now, NULL);
	}
}

void	dine(t_philo_n *philo, pthread_mutex_t *cs1, pthread_mutex_t *cs2)
{
	while (is_death(philo->apoptosis, READ) != DIE
		&& (!*philo->needed_dines || (philo->n_dines < *philo->needed_dines)))
	{
		philo->status = (philo->status + 1) % 3;
		gettimeofday(&philo->updated_time, NULL);
		talk(philo, philo->status, NULL);
		if (philo->status == THINK)
			getchopsticks(philo, cs1, cs2);
		else
			live(philo, philo->v_func->time[philo->status]);
		if (philo->status == EAT)
		{
			pthread_mutex_unlock(cs1);
			pthread_mutex_unlock(cs2);
			philo->n_dines++;
		}
	}
}

void	*philosophare(void *varg)
{
	t_philo_n	*philo;

	philo = (t_philo_n *)varg;
	if (philo->id % 2)
		dine(philo, &philo->chopstick, &philo->next->chopstick);
	else
		dine(philo, &philo->next->chopstick, &philo->chopstick);
	return (NULL);
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
	cnt = 0;
	while (cnt < philo->n_philos)
	{
		pthread_join(philo->philos.head->thread, NULL);
		philo->philos.head = philo->philos.head->next;
		cnt++;
	}
}
