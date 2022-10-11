/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 19:08:25 by rgallego          #+#    #+#             */
/*   Updated: 2022/10/11 18:32:25 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_H
# define ALGORITHM_H

# include "queue.h"
# include "btree.h"
# include "stack.h"
# include "mvntslist.h"
# include "mvmnts.h"
# include "push_swap.h"

typedef struct s_vector
{
	int	n_elem;
	int	*nums;
}	t_vector;

int		is_sorted(t_queue *queue);
void	algorithm_prep(t_queue queue);
void	ft_mergesort(t_push_swap a, int half);
void	the_algorithm(t_push_swap push_swap, t_stack *a_stck);

#endif
