/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:21:11 by rgallego          #+#    #+#             */
/*   Updated: 2022/10/11 16:30:05 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "queue.h"
#include "list.h"
#include "utils.h"
#include "algorithm.h"

typedef struct s_push_swap
{
	t_queue	*a;
	t_queue	*b;
	t_list	*mvnts;
}	t_push_swap;

#endif
