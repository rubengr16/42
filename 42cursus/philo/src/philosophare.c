/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophare.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:40:25 by rgallego          #+#    #+#             */
/*   Updated: 2023/02/26 21:12:01 by rgallego         ###   ########.fr       */
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
	while (*philo->apoptosis != DIE && getutimediff(philo->updated_time, now) < (time * US_MS)
		&& (!chopstick || *chopstick == BUSY))
		{
			usleep(50);
			gettimeofday(&now, NULL);
		}
	if (philo->status == EAT)
		philo->n_dines++;
	if (chopstick && *chopstick == BUSY && getutimediff(philo->updated_time, now) > (time * US_MS))
		*philo->apoptosis = DIE;
}

int	getchopstick(t_philo_n *philo, t_chopstick *chopstick)
{
	if (chopstick->value == BUSY)
		live(philo, &chopstick->value, philo->v_func->time[THINK]);
	if (*philo->apoptosis == DIE)
	{
		talk(philo, -1, DIE_MSG);
		return (-1);
	}
	pthread_mutex_lock(&chopstick->mutex);
	chopstick->value = BUSY;
	talk(philo, -1, TAKE_MSG);
	return (0);
}

void	dine(t_philo_n *philo, t_chopstick *cs1, t_chopstick *cs2)
{
	while (*philo->apoptosis != DIE
		&& (!*philo->needed_dines ||(philo->n_dines < *philo->needed_dines))
		&& (philo->status != THINK || (philo->status == THINK
		&& (getchopstick(philo, cs1) >= 0 && getchopstick(philo, cs2) >= 0))))
	{
		philo->status = (philo->status + 1) % 3;
		talk(philo, philo->status, NULL);
		if (philo->status != THINK)
			live(philo, NULL, philo->v_func->time[philo->status]);
		if (philo->status == EAT)
		{
			cs1->value = FREE;
			pthread_mutex_unlock(&cs1->mutex);
			cs2->value = FREE;
			pthread_mutex_unlock(&cs2->mutex);
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
\
void	set_the_table(t_philo *philo)
{
	unsigned int	cnt;

	cnt = 0;
	while(cnt < philo->n_philos)
	{
		pthread_create(&philo->philos.head->thread, NULL, philosophare,
			philo->philos.head);
		philo->philos.head = philo->philos.head->next;
		cnt++;
	}
	cnt = 0;
	philo->philos.head = philo->philos.head->next;
	while (cnt < philo->n_philos)
	{
		pthread_join(philo->philos.head->thread, NULL);
		philo->philos.head = philo->philos.head->next;
		cnt++;
	}
}
