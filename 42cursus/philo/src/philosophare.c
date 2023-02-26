/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophare.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:40:25 by rgallego          #+#    #+#             */
/*   Updated: 2023/02/26 01:11:15 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	talk(t_philo_n *philo, int status, char *msg)
{
	struct timeval	now;
	unsigned long	time;

	if (gettimeofday(&now, NULL))
		*philo->apoptosis = ERR_SYS;
	time = getutimediff(*philo->birth_time, now);
	if (!msg)
	{
		msg = philo->v_func->status[status];
		philo->status = status;
	}
	if (pthread_mutex_lock(philo->printf_mutex))
		*philo->apoptosis = ERR_SYS;
	printf("%ld %u %s\n", time, philo->id, msg);
	if (pthread_mutex_unlock(philo->printf_mutex))
		*philo->apoptosis = ERR_SYS;
}

void	live(t_philo_n *philo, int *chopstick, unsigned long time)
{
	struct timeval	now;

	if (gettimeofday(&now, NULL))
		*philo->apoptosis = ERR_SYS;
	if (!chopstick)
		philo->updated_time = now;
	while (*philo->apoptosis < 0
		&& getutimediff(philo->updated_time, now) < time
		&& (!chopstick || *chopstick == BUSY))
	{
		if (usleep(50))
			*philo->apoptosis = ERR_SYS;
		if (gettimeofday(&now, NULL))
			*philo->apoptosis = ERR_SYS;
	}
	if (philo->status == EAT)
		philo->n_dines++;
	if (chopstick && *chopstick == BUSY
		&& getutimediff(philo->updated_time, now) > time)
		*philo->apoptosis = DIE;
}

void	dine(t_philo_n *philo, t_chopstick *cs1, t_chopstick *cs2)
{
	while (*philo->apoptosis < 0
		&& (!*philo->needed_dines || (philo->n_dines < *philo->needed_dines))
		&& (philo->status != THINK || (philo->status == THINK
				&& (getchopstick(philo, cs1) >= 0
					&& getchopstick(philo, cs2) >= 0))))
	{
		philo->status = (philo->status + 1) % 3;
		talk(philo, philo->status, NULL);
		if (philo->status != THINK)
			live(philo, NULL, philo->v_func->time[philo->status]);
		if (philo->status == EAT)
		{
			cs1->value = FREE;
			if (pthread_mutex_unlock(&cs1->mutex))
				*philo->apoptosis = ERR_SYS;
			cs2->value = FREE;
			if (pthread_mutex_unlock(&cs2->mutex))
				*philo->apoptosis = ERR_SYS;
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

int	set_the_table(t_philo *philo)
{
	unsigned int	cnt;

	cnt = 0;
	while (cnt < philo->n_philos && philo->apoptosis != ERR_SYS)
	{
		if (pthread_create(&philo->philos.head->thread, NULL,
				philosophare, philo->philos.head))
			philo->apoptosis = ERR_SYS;
		philo->philos.head = philo->philos.head->next;
		cnt++;
	}
	cnt = 0;
	while (cnt < philo->n_philos && philo->apoptosis != ERR_SYS)
	{
		if (pthread_join(philo->philos.head->thread, NULL))
			philo->apoptosis = ERR_SYS;
		philo->philos.head = philo->philos.head->next;
		cnt++;
	}
	if (philo->apoptosis == ERR_SYS)
		return (ERR_SYS);
	return (0);
}
