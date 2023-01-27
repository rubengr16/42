/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 20:37:02 by rgallego          #+#    #+#             */
/*   Updated: 2023/01/20 16:37:44 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>

typedef struct s_snode
{
	int				max;
	int				min;
	struct s_snode	*next;
}	t_snode;

typedef struct s_stack
{
	t_snode	*head;
}	t_stack;

/************************** BASIC STACK FUNCTIONS *************************** */
t_snode	*newsnode(int min, int max);
t_stack	*stackinit(void);
t_stack	*stackinitnode(t_snode	*snode);
t_stack	*stackinitminmax(int min, int max);
void	stackpush(t_stack *stack, t_snode *node);
t_snode	*stackpush_minmax(t_stack *stack, int min, int max);
t_snode	*stackpop(t_stack *stack);
void	stackdelall(t_stack *stack);

#endif
