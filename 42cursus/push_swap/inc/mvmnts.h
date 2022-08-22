/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvmnts.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 16:05:19 by rgallego          #+#    #+#             */
/*   Updated: 2022/08/22 18:51:45 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MVMNTS_H
# define MVMNTS_H

# include "libft.h"
# include "queue.h"

/* **************************** SWAP FUNCTIONS ****************************** */
void	swap_a(t_queue *a);
void	swap_b(t_queue *b);
void	swap_ab(t_queue *a, t_queue *b);

/* **************************** PUSH FUNCTIONS ****************************** */
void	push_a(t_queue *a, t_queue *b);
void	push_b(t_queue *a, t_queue *b);

/* *************************** ROTATE FUNCTIONS ***************************** */
int		rotate_queue(t_queue *queue);
void	rotate_a(t_queue *a);
void	rotate_b(t_queue *b);
void	rotate_ab(t_queue *a, t_queue *b);

/* *********************** REVERSE ROTATE FUNCTIONS ************************* */
int		reverse_rotate_queue(t_queue *queue);
void	reverse_rotate_a(t_queue *a);
void	reverse_rotate_b(t_queue *b);
void	reverse_rotate_ab(t_queue *a, t_queue *b);

#endif
