/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:02:09 by rgallego          #+#    #+#             */
/*   Updated: 2023/03/20 23:47:57 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo			philo;

	if (argc != 5 && argc != 6)
	{
		printf("Error. Arguments: nbr_of_philo time_to_die time_to_eat ");
		printf("time_to_sleep [nbr_of_times_each_philo_must_eat]\n");
		return (1);
	}
	philo = (t_philo){};
	philo.v_func = (t_v_func){{0, 0, 0},
	{THINK_MSG, EAT_MSG, SLEEP_MSG, NULL}};
	if (parser(&philo, &argv[1]) < 0)
		return (1);
	if (philo_sire(&philo, &philo.philos, philo.n_philos) < 0)
	{
		philo_killer(&philo);
		return (1);
	}
	set_the_table(&philo);
	philo_killer(&philo);
	return (0);
}
