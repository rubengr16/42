/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:03:20 by rgallego          #+#    #+#             */
/*   Updated: 2023/02/26 20:24:50 by rgallego         ###   ########.fr       */
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
# define S_US 1000000
# define US_MS 1000

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

# define READ -2

typedef struct s_vital_functions
{
	unsigned int	time[3];
	char			*status[4];
}	t_vital_functions;

typedef struct s_rw_lock
{
	int					value;
	pthread_mutex_t		rw_lock;
}	t_rw_lock;


typedef struct s_chopstick
{
	t_rw_lock		lock;
	pthread_mutex_t	mutex;
}	t_chopstick;

typedef struct s_philo_n
{
	unsigned int		id;
	unsigned int		n_dines;
	unsigned int		*needed_dines;
	int					status;
	char				*status_msg;
	t_vital_functions	*v_func;
	t_rw_lock			*apoptosis;
	struct timeval		updated_time;
	struct timeval		*birth_time;
	pthread_t			thread;
	t_chopstick			chopstick;
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
	t_vital_functions	v_func;
	t_rw_lock			apoptosis;
	struct timeval		start_time;
	pthread_mutex_t		printf_mutex;
	t_philo_q			philos;
}	t_philo;

int				parser(t_philo *philo, char **argv);
int				philo_sire(t_philo *philo, t_philo_q *q, unsigned int n);
void			philo_killer(t_philo_q *queue);
unsigned long	getutimediff(struct timeval start, struct timeval end);
void			set_the_table(t_philo *philo);
int				rw_value(t_rw_lock *chopstick, int	value);


#endif
