/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:53:55 by rgallego          #+#    #+#             */
/*   Updated: 2023/02/22 17:37:58 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_BONUS_H
# define UTILS_BONUS_H

# include "libft.h"
# include "queue.h"
# include "mvnts.h"
# include "mvntslist.h"
# include "utils.h"
# include "bonus.h"

void	argtostack_bonus(t_queue *queue, char **argv);
void	push_swap_init_bonus(t_push_swap_bonus *push_swap);
int		execute_mvnt(t_push_swap_bonus push_swap, char *mvnt, int len);

#endif
