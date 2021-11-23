/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvmnts.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 16:05:19 by rgallego          #+#    #+#             */
/*   Updated: 2021/11/23 18:43:07 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MVMNTS_H
# define MVMNTS_H

#include "../libft/libft.h"
#include "../queue/queue.h"

/* ************************** ALLOWED FUNCTIONS ****************************** */
/* *************************** ROTATE FUNCTIONS ****************************** */
int		ft_rotate_queue(t_queue *queue)
void	ft_rotate_a(t_queue *a);
void	ft_rotate_b(t_queue *b);
void	ft_rotate_ab(t_queue *a, t_queue *b);
/* *********************** REVERSE ROTATE FUNCTIONS ************************** */
int		ft_reverse_rotate_queue(t_queue *queue)
void	ft_reverse_rotate_a(t_queue *a);
void	ft_reverse_rotate_b(t_queue *b);
void	ft_reverse_rotate_ab(t_queue *a, t_queue *b);

#endif
