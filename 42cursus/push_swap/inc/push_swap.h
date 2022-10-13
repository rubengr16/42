/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:21:11 by rgallego          #+#    #+#             */
/*   Updated: 2022/10/11 18:24:39 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "queue.h"
#include "mvntslist.h"

typedef struct s_push_swap
{
	t_queue		*a;
	t_queue		*b;
	t_mvntslist	*mvnts;
}	t_push_swap;

#endif
