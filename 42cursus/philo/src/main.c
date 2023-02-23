/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:02:09 by rgallego          #+#    #+#             */
/*   Updated: 2023/02/23 17:31:28 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(void)
{
	// t_philo	philo;

	// if (argc != 4 && argc != 5)
	// 	printf("Error. Arguments: nbr_of_philo time_to_die time_to_eat");
	// 	printf("time_to_sleep [nbr_of_times_each_philo_must_eat]");
	printf("before\n");
	usleep(5000000);
	printf("after\n");
}

// void	argtostack(t_queue *queue, char **argv)
// {
// 	char	**set;
// 	int		nb;
// 	int		cnt;
// 	int		cnt_set;

// 	if (!argv)
// 		ft_error("Error. No argv.", STDERR_FILENO, ERR_USR);
// 	cnt = 0;
// 	while (argv[cnt])
// 	{
// 		set = ft_split(argv[cnt], ' ');
// 		if (!set)
// 			ft_error("Error. Split failed.", STDERR_FILENO, ERR_USR);
// 		cnt_set = 0;
// 		while (set[cnt_set])
// 		{
// 			nb = ft_atoi_err(set[cnt_set]);
// 			if (nbrepeated(queue, nb))
// 				ft_error("Error. Number repeated.", STDERR_FILENO, ERR_USR);
// 			(void)queueadd_back_num(queue, nb);
// 			cnt_set++;
// 		}
// 		ft_free_split(set);
// 		cnt++;
// 	}
// }
