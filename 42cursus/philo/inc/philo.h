/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:03:20 by rgallego          #+#    #+#             */
/*   Updated: 2023/03/28 19:42:00 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

# define INT_MAX 2147483648

# define S_TO_MS 1000
# define US_TO_MS 1000

# define MIN_USLEEP 100
# define RENDEZVOUS_TIME 400

# define THINK 0
# define EAT 1
# define SLEEP 2
# define DIE -1

# define EAT_MSG "is eating"
# define SLEEP_MSG "is sleeping"
# define THINK_MSG "is thinking"
# define TAKE_MSG "has taken a fork"
# define DIE_MSG "died"

# define FREE 1
# define BUSY 0

# define READ 0

typedef struct s_v_func
{
	unsigned int	time[3];
	char			*status[4];
}	t_v_func;

typedef struct s_apoptosis
{
	unsigned int	apoptosis;
	pthread_mutex_t	mutex;
}	t_apoptosis;

typedef struct s_philo_n
{
	unsigned int		id;
	unsigned int		n_dines;
	unsigned int		*needed_dines;
	unsigned int		status;
	t_v_func			*v_func;
	t_apoptosis			*apoptosis;
	struct timeval		updated_time;
	struct timeval		last_sup_time;
	struct timeval		*birth_time;
	pthread_t			thread;
	pthread_mutex_t		chopstick;
	pthread_mutex_t		*printf_mutex;
	struct s_philo_n	*next;
	struct s_philo_n	*prvs;
}	t_philo_n;

typedef struct s_philo_q
{
	unsigned int	n_philos;
	t_philo_n		*head;
}	t_philo_q;

typedef struct s_philo
{
	unsigned int		n_philos;
	unsigned int		needed_dines;
	t_v_func			v_func;
	t_apoptosis			apoptosis;
	struct timeval		start_time;
	pthread_mutex_t		printf_mutex;
	t_philo_q			philos;
}	t_philo;

int				parser(t_philo *philo, char **argv);
unsigned long	getutimediff(struct timeval start, struct timeval end);
int				is_death(t_apoptosis *apoptosis, int value);
int				philo_sire(t_philo *philo, t_philo_q *q, unsigned int n);
void			philo_killer(t_philo *philo);
void			set_the_table(t_philo *philo);
void			talk(t_philo_n *philo, int status, char *msg);
void			*philosophare(void *varg);

#endif
