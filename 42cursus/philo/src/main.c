/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:02:09 by rgallego          #+#    #+#             */
/*   Updated: 2023/02/25 22:40:37 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void *myThreadFun(void *vargp)
// {
// 	int	*nb;
//     sleep(5);
// 	nb = (int *)vargp;
// 	(*nb) += 2;
//     printf("Printing Hello Ruben from Thread >>> nb = %d\n", *nb);
//     return NULL;
// }

// void	test(void)
// {
// 	// USLEEP test
// 	// printf("before\n");
// 	// usleep(5000000);
// 	// printf("after\n");

// 	// GETTIMEOFDAY test
// 	// struct timeval current_time;
// 	// gettimeofday(&current_time, NULL);
// 	// printf("seconds : %ld\nmicro seconds : %d", current_time.tv_sec, current_time.tv_usec);

// 	// THREAD TEST
//     // pthread_t	thread_id;
// 	// int			nb;
// 	// nb = 0;
//     // printf("Before Thread >>> nb = %d\n", nb);
//     // pthread_create(&thread_id, NULL, myThreadFun, &nb);
//     // pthread_join(thread_id, NULL);
//     // printf("After Thread >>> nb = %d\n", nb);

// 	// USLEEP and GETTIMEOFDAY test
// 	struct timeval current_time;
// 	gettimeofday(&current_time, NULL);
// 	printf("seconds : %ld\nmicro seconds : %d\n", current_time.tv_sec, current_time.tv_usec);
// 	usleep(5);
// 	gettimeofday(&current_time, NULL);
// 	printf("seconds : %ld\nmicro seconds : %d\n", current_time.tv_sec, current_time.tv_usec);
// }

int	main(int argc, char **argv)
{
	t_philo			philo;

	if (argc != 5 && argc != 6)
	{
		printf("Error. Arguments: nbr_of_philo time_to_die time_to_eat ");
		printf("time_to_sleep [nbr_of_times_each_philo_must_eat]\n");
		return (1);
	}
	philo = (t_philo){0, 0, {{0, 0, 0}, {THINK_MSG, EAT_MSG, SLEEP_MSG, NULL}},
		0, philo.start_time, philo.printf_mutex, {0, NULL}};
	if (parser(&philo, &argv[1]) < 0)
		return (1);
	if (philo_sire(&philo, &philo.philos, philo.n_philos) < 0)
	{
		philo_killer(&philo.philos);
		return (1);
	}
	set_the_table(&philo);
	philo_killer(&philo.philos);
	return (0);
}
