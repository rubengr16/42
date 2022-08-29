/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 19:08:25 by rgallego          #+#    #+#             */
/*   Updated: 2022/08/29 21:36:39 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_H
# define ALGORITHM_H

# include "queue.h"
# include "mvmnts.h"

typedef struct s_vector
{
	int	n_elem;
	int	*nums;
}	t_vector;

int			sortbase(t_queue *queue);
void		algorithm_prep(t_queue queue);
void	ft_mergesort(t_queue *a, t_queue *b, int size);

#endif
