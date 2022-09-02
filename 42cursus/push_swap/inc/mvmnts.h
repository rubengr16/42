/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvmnts.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 16:05:19 by rgallego          #+#    #+#             */
/*   Updated: 2022/09/01 09:17:55 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MVMNTS_H
# define MVMNTS_H

# include "libft.h"
# include "queue.h"

/* **************************** SWAP FUNCTIONS ****************************** */
void	swap(t_queue *queue);
void	swap_both(t_queue *a, t_queue *b);

/* **************************** PUSH FUNCTIONS ****************************** */
void	push(t_queue *dst, t_queue *src);

/* *************************** ROTATE FUNCTIONS ***************************** */
int		rotate_queue(t_queue *queue);
void	rotate(t_queue *queue);
void	rotate_both(t_queue *a, t_queue *b);

/* *********************** REVERSE ROTATE FUNCTIONS ************************* */
int		reverse_rotate_queue(t_queue *queue);
void	reverse_rotate(t_queue *queue);
void	reverse_rotate_both(t_queue *a, t_queue *b);

#endif
