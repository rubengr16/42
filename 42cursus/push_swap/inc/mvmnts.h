/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvmnts.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 16:05:19 by rgallego          #+#    #+#             */
/*   Updated: 2022/10/11 18:18:13 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MVMNTS_H
# define MVMNTS_H

# include "libft.h"
# include "queue.h"
# include "mvntslist.h"

/* **************************** SWAP FUNCTIONS ****************************** */
void	swap(t_queue *queue, t_mvntslist *mvnts);
void	swap_both(t_queue *a, t_queue *b, t_mvntslist *mvnts);

/* **************************** PUSH FUNCTIONS ****************************** */
void	push(t_queue *dst, t_queue *src, t_mvntslist *mvnts);

/* *************************** ROTATE FUNCTIONS ***************************** */
int		rotate_queue(t_queue *queue);
void	rotate(t_queue *queue, t_mvntslist *mvnts);
void	rotate_both(t_queue *a, t_queue *b, t_mvntslist *mvnts);

/* *********************** REVERSE ROTATE FUNCTIONS ************************* */
int		reverse_rotate_queue(t_queue *queue);
void	reverse_rotate(t_queue *queue, t_mvntslist *mvnts);
void	reverse_rotate_both(t_queue *a, t_queue *b, t_mvntslist *mvnts);

#endif
