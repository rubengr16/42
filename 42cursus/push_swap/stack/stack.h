/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 16:05:19 by rgallego          #+#    #+#             */
/*   Updated: 2021/11/21 20:18:28 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

#include "../libft/libft.h"

typedef struct s_node
{
	int				num;
	struct s_node	*next;
	struct s_node	*prvs;
}	t_node;

typedef struct s_stack
{
	int		n_elem;
		t_node	*head;
}	t_stack;

/* ************************** ALLOWED FUNCTIONS ****************************** */
/* *************************** ROTATE FUNCTIONS ****************************** */
void	ft_rotate_a(t_stack *a)
void	ft_rotate_b(t_stack *b)
void	ft_rotate_ab(t_stack *a, t_stack *b)
/* *********************** REVERSE ROTATE FUNCTIONS ************************** */
void	ft_reverse_rotate_a(t_stack *a)
void	ft_reverse_rotate_b(t_stack *b)
void	ft_reverse_rotate_ab(t_stack *a, t_stack *b)
#endif
