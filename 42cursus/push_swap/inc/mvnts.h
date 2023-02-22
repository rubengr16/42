/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvnts.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 16:05:19 by rgallego          #+#    #+#             */
/*   Updated: 2023/02/22 17:29:34 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MVNTS_H
# define MVNTS_H

# include "libft.h"
# include "queue.h"
# include "mvntslist.h"

/* **************************** SWAP FUNCTIONS ****************************** */
int		swap_queue(t_queue *queue);
void	swap(t_queue *queue, t_mvntslist *mvnts);
void	swap_both(t_queue *a, t_queue *b, t_mvntslist *mvnts);

/* **************************** PUSH FUNCTIONS ****************************** */
int		push_queue(t_queue *dst, t_queue *src);
void	push(t_queue *dst, t_queue *src, t_mvntslist *mvnts);

/* *************************** ROTATE FUNCTIONS ***************************** */
int		rotate_queue(t_queue *queue);
void	rotate(t_queue *queue, t_mvntslist *mvnts);
void	rotate_both(t_queue *a, t_queue *b, t_mvntslist *mvnts);

/* *********************** REVERSE ROTATE FUNCTIONS ************************* */
int		rev_rotate_queue(t_queue *queue);
void	rev_rotate(t_queue *queue, t_mvntslist *mvnts);
void	rev_rotate_both(t_queue *a, t_queue *b, t_mvntslist *mvnts);

#endif
