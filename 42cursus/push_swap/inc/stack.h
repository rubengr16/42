/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 20:37:02 by rgallego          #+#    #+#             */
/*   Updated: 2022/08/31 10:18:33 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>

typedef struct s_snode
{
	int				num;
	struct s_snode	*next;
}	t_snode;

typedef struct s_stack
{
	t_snode	*head;
}	t_stack;

/************************** BASIC STACK FUNCTIONS *************************** */
t_snode	*newsnode(int num);
t_stack	*stackinit(void);
t_stack	*stackinitnode(t_snode	*snode);
t_stack	*stackinitnum(int num);
void	stackpush(t_stack *stack, t_snode *node);
t_snode	*stackpush_num(t_stack *stack, int num);
t_snode	*stackpop(t_stack *stack);
void	stackdelall(t_stack *stack);

#endif
