/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:02:09 by rgallego          #+#    #+#             */
/*   Updated: 2023/02/26 20:05:46 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo			philo;

	if (argc != 5 && argc != 6)
	{
		printf("Error. Args: nb_philo t_die t_eat t_sleep [nb_eat]\n");
		return (-1);
	}
	philo = (t_philo){0, 0, {{0, 0, 0}, {THINK_MSG, EAT_MSG, SLEEP_MSG, NULL}},
		{0, philo.apoptosis.rw_lock}, philo.start_time, philo.printf_mutex,
		{0, NULL}};
	if (parser(&philo, &argv[1]) < 0)
		return (-1);
	if (philo_sire(&philo, &philo.philos, philo.n_philos) < 0)
	{
		(void)philo_killer(&philo.philos);
		printf("Error. One (or more) of the function calls failed.");
		return (-1);
	}
	set_the_table(&philo);
	philo_killer(&philo.philos);
	if (philo.apoptosis == ERR_SYS)
	{
		printf("Error. One (or more) of the function calls failed.");
		return (-1);
	}
	return (0);
}
