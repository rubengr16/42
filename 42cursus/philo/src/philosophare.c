/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophare.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:40:25 by rgallego          #+#    #+#             */
/*   Updated: 2023/03/07 21:05:46 by rgallego         ###   ########.fr       */
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

void	live(t_philo_n *philo, t_rw_lock *cs, unsigned long time)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	if (philo->status == THINK && philo->n_dines)
		time = philo->v_func->time[THINK] - philo->v_func->time[EAT]
			- philo->v_func->time[SLEEP];
	while (rw_value(philo->apoptosis, READ) != DIE
		&& getutimediff(philo->updated_time, now) < time
		&& (!cs || rw_value(&cs, READ) == BUSY))
	{
		usleep(100);
		gettimeofday(&now, NULL);
	}
	if (cs && getutimediff(philo->updated_time, now) >= time)
	{
		(void)rw_value(philo->apoptosis, DIE);
		talk(philo, -1, DIE_MSG);
	}
	if (philo->status == EAT)
		philo->n_dines++;
}

void	dine(t_philo_n *philo, t_rw_lock *cs1, t_rw_lock *cs2)
{
	while (rw_value(philo->apoptosis, READ) != DIE
		&& (!*philo->needed_dines || (philo->n_dines < *philo->needed_dines))
		&& (philo->status != THINK || (philo->status == THINK
				&& (!getchopstick(philo, cs1) && !getchopstick(philo, cs2)))))
	{
		gettimeofday(&philo->updated_time, NULL);
		philo->status = (philo->status + 1) % 3;
		talk(philo, philo->status, NULL);
		if (philo->status != THINK)
			live(philo, NULL, philo->v_func->time[philo->status]);
		if (philo->status == EAT)
		{
			(void)rw_value(&cs1, FREE);
			(void)rw_value(&cs2, FREE);
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

	pthread_mutex_init(&philo->apoptosis.rw_lock, NULL);
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
	philo->philos.head = philo->philos.head->next;
	while (cnt < philo->n_philos)
	{
		pthread_join(philo->philos.head->thread, NULL);
		philo->philos.head = philo->philos.head->next;
		cnt++;
	}
}
