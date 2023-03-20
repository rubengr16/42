/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophare.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:40:25 by rgallego          #+#    #+#             */
/*   Updated: 2023/03/20 23:45:00 by rgallego         ###   ########.fr       */
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

static void	live(t_philo_n *philo, unsigned long time)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	while (is_death(philo->apoptosis, READ) != DIE
		&& getutimediff(philo->updated_time, now) < time)
	{
		usleep(MIN_USLEEP);
		gettimeofday(&now, NULL);
	}
}

static void	getchopsticks(t_philo_n *philo,
	pthread_mutex_t *cs1, pthread_mutex_t *cs2)
{
	if (cs1 == cs2)
		live(philo, philo->v_func->time[THINK]);
	if (is_death(philo->apoptosis, READ) != DIE)
	{
		pthread_mutex_lock(cs1);
		if (is_death(philo->apoptosis, READ) != DIE)
		{
			talk(philo, -1, TAKE_MSG);
			pthread_mutex_lock(cs2);
			if (is_death(philo->apoptosis, READ) != DIE)
			{
				gettimeofday(&philo->last_sup_time, NULL);
				philo->updated_time = philo->last_sup_time;
				talk(philo, -1, TAKE_MSG);
			}
			else
				pthread_mutex_unlock(cs2);
		}
		else
			pthread_mutex_unlock(cs1);
	}
}

static void	dine(t_philo_n *philo, pthread_mutex_t *cs1, pthread_mutex_t *cs2)
{
	getchopsticks(philo, cs1, cs2);
	while (is_death(philo->apoptosis, READ) != DIE
		&& (!*philo->needed_dines || (philo->n_dines < *philo->needed_dines)))
	{
		philo->status = (philo->status + 1) % 3;
		gettimeofday(&philo->updated_time, NULL);
		talk(philo, philo->status, NULL);
		if (philo->status == THINK)
		{
			usleep(RENDEZVOUS_TIME);
			getchopsticks(philo, cs1, cs2);
		}
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
