/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:14:24 by rgallego          #+#    #+#             */
/*   Updated: 2023/03/20 23:38:55 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_atoi(const char *s, unsigned int *num)
{
	*num = 0;
	while (*s && (*s == '\t' || *s == '\n' || *s == '\v' || *s == '\f'
			|| *s == '\r' || *s == ' '))
		s++;
	if (*s == '+')
		s++;
	if (*s < '0' || '9' < *s)
	{
		printf("Error. Bad numbers as input.");
		return (-1);
	}
	while (*s && '0' <= *s && *s <= '9')
	{
		*num = *num * 10 + (*s - '0');
		s++;
	}
	if ((*s && (*s < '0' || '9' < *s)) || *num >= INT_MAX)
	{
		printf("Error. Bad numbers as input.");
		return (-1);
	}
	return (*num);
}

int	parser(t_philo *philo, char **argv)
{
	int	cnt;

	cnt = 0;
	if (ft_atoi(argv[cnt], &philo->n_philos) < 0)
		return (-1);
	cnt++;
	while (cnt < 4 && argv[cnt])
	{
		if (ft_atoi(argv[cnt], &philo->v_func.time[cnt - 1]) < 0)
			return (-1);
		cnt++;
	}
	if (argv[cnt])
	{
		if (ft_atoi(argv[cnt], &philo->needed_dines) <= 0)
			return (-1);
	}
	return (cnt);
}

unsigned long	getutimediff(struct timeval start, struct timeval end)
{
	return ((end.tv_sec - start.tv_sec) * S_TO_MS
		+ (end.tv_usec - start.tv_usec) / US_TO_MS);
}

int	is_death(t_apoptosis *apoptosis, int value)
{
	int	death;

	pthread_mutex_lock(&apoptosis->mutex);
	if (value != READ)
		apoptosis->apoptosis = value;
	death = apoptosis->apoptosis;
	pthread_mutex_unlock(&apoptosis->mutex);
	return (death);
}
