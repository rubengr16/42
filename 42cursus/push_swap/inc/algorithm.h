/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 19:08:25 by rgallego          #+#    #+#             */
/*   Updated: 2023/02/22 17:36:38 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_H
# define ALGORITHM_H

# include "queue.h"
# include "stack.h"
# include "mvntslist.h"
# include "mvnts.h"
# include "utils.h"
# include "push_swap.h"

typedef struct s_vector
{
	int	n_elem;
	int	*nums;
}	t_vector;

int		group_sorted(t_queue *queue, t_snode node);
void	sort_base(t_queue *queue, t_mvntslist *mvnts);
void	algorithm_prep(t_queue queue, t_stack *stack);
void	fill_queue_b(t_push_swap push_swap);
void	merge_mdn(t_push_swap push_swap);
void	order_a(t_push_swap push_swap, t_snode *group);
void	order_b(t_push_swap push_swap, t_snode *group);
int		calc_median(int min, int max);
int		on_range(int min, int max, int value);
void	optimizer(t_mvntslist *mvnts);
void	optimize_r(t_mvntslist *mvnts, t_lnode *first_r, int n_iter, int cnt);
void	optimize_rr(t_mvntslist *mvnts, t_lnode *first_r, int n_iter, int cnt);
t_snode	*make_new_groups(t_stack *stack, t_snode	*group);
int		move_nbs(t_queue *q1, t_queue *q2, t_mvntslist *mvnts, t_snode group);

#endif
