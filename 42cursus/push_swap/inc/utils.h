/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:53:55 by rgallego          #+#    #+#             */
/*   Updated: 2022/10/11 20:17:59 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdio.h>
# include "libft.h"
# include "queue.h"
# include "mvntslist.h"

void	argtostack(t_queue *queue, char **argv);
void	push_swap_init(t_queue **a, t_queue **b, t_mvntslist **mvnts);
void	print_mvnts(t_mvntslist *mvnts);

#endif
