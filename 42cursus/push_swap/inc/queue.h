/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 16:05:19 by rgallego          #+#    #+#             */
/*   Updated: 2022/09/01 09:41:40 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# include <stdlib.h>

typedef struct s_qnode
{
	int				num;
	struct s_qnode	*next;
	struct s_qnode	*prvs;
}	t_qnode;

typedef struct s_queue
{
	int		n_elem;
	char	id;
	t_qnode	*head;
}	t_queue;

/************************** BASIC QUEUE FUNCTIONS *************************** */
t_queue	*queueinit(char c);
t_qnode	*newqnode(int num);
void	queueadd_back(t_queue *queue, t_qnode *node);
t_qnode	*queueadd_back_num(t_queue *queue, int num);
void	queueadd_front(t_queue *queue, t_qnode *node);
t_qnode	*queueadd_front_num(t_queue *queue, int num);
t_qnode	*queuepop(t_queue *queue);
void	queuedelone(t_queue *queue);
void	queuedelall(t_queue *queue);

#endif
