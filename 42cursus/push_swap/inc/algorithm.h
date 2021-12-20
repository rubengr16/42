/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 19:08:25 by rgallego          #+#    #+#             */
/*   Updated: 2021/12/20 15:35:08 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_H
# define ALGORITHM_H

# include "queue.h"
# include "mvmnts.h"

int		ft_issorted(t_queue *queue);
void	ft_setstate(t_queue *queue, int n_elem, int state);
int		ft_average(t_queue *queue);

int		ft_n_rot(t_queue	*queue, int avg);
int		ft_n_revrot(t_queue	*queue, int avg);
void	ft_rotpush(t_queue *a, t_queue *b, int avg, int lvl);
void	ft_revrotpush(t_queue *a, t_queue *b, int avg, int lvl);

void	ft_sortbase(t_queue *queue);
void	ft_sortrecavg(t_queue *a, t_queue *b, int lvl);

#endif
