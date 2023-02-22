/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:53:55 by rgallego          #+#    #+#             */
/*   Updated: 2023/02/22 14:35:12 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "libft.h"
# include "queue.h"
# include "mvntslist.h"
# include "push_swap.h"

void	argtostack(t_queue *queue, char **argv);
void	push_swap_init(t_push_swap *push_swap);
void	print_mvnts(t_mvntslist *mvnts);

#endif
