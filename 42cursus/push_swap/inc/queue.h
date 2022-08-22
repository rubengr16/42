/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 16:05:19 by rgallego          #+#    #+#             */
/*   Updated: 2022/08/22 18:57:59 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# include <stdlib.h>

typedef struct s_node
{
	int				num;
	int				idx;
	struct s_node	*next;
	struct s_node	*prvs;
}	t_node;

typedef struct s_queue
{
	int		n_elem;
	t_node	*head;
}	t_queue;

/************************** BASIC QUEUE FUNCTIONS *************************** */
t_queue	*queueinit(void);
t_node	*newnode(int num);
void	queueadd_back(t_queue *queue, t_node *node);
void	queueadd_back_num(t_queue *queue, int num);
void	queueadd_front(t_queue *queue, t_node *node);
void	queueadd_front_num(t_queue *queue, int num);
t_node	*queuepop(t_queue *queue);
void	queuedelone(t_queue *queue);
void	queuedelall(t_queue **queue);

#endif
