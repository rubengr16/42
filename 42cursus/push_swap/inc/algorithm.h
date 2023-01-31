/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 19:08:25 by rgallego          #+#    #+#             */
/*   Updated: 2023/01/31 14:18:28 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_H
# define ALGORITHM_H

# include "queue.h"
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
void	algorithm_prep(t_queue queue, t_stack *stack);
void	fill_queue_b(t_push_swap push_swap);
void	merge_mdn(t_push_swap push_swap);
int		calc_median(int min, int max);
void	optimizer(t_mvntslist *mvnts);


// DELETE when finished
void	print_stack(t_stack stack);
void	print_queue(t_queue queue);

#endif
