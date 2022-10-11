/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvmnts.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 16:05:19 by rgallego          #+#    #+#             */
/*   Updated: 2022/10/11 16:07:44 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MVMNTS_H
# define MVMNTS_H

# include "libft.h"
# include "queue.h"
# include "list.h"

/* **************************** SWAP FUNCTIONS ****************************** */
void	swap(t_queue *queue, t_list *mvnts);
void	swap_both(t_queue *a, t_queue *b, t_list *mvnts);

/* **************************** PUSH FUNCTIONS ****************************** */
void	push(t_queue *dst, t_queue *src, t_list *mvnts);

/* *************************** ROTATE FUNCTIONS ***************************** */
int		rotate_queue(t_queue *queue);
void	rotate(t_queue *queue, t_list *mvnts);
void	rotate_both(t_queue *a, t_queue *b, t_list *mvnts);

/* *********************** REVERSE ROTATE FUNCTIONS ************************* */
int		reverse_rotate_queue(t_queue *queue);
void	reverse_rotate(t_queue *queue, t_list *mvnts);
void	reverse_rotate_both(t_queue *a, t_queue *b, t_list *mvnts);

#endif
