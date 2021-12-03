/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 16:05:19 by rgallego          #+#    #+#             */
/*   Updated: 2021/12/03 20:35:52 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# include <stdlib.h>

typedef struct s_node
{
	int				num;
	struct s_node	*next;
	struct s_node	*prvs;
}	t_node;

typedef struct s_queue
{
	int		n_elem;
	t_node	*head;
}	t_queue;

/************************** BASIC QUEUE FUNCTIONS *************************** */
t_queue	*ft_queueinit(void);
t_node	*ft_newnode(int num);
void	ft_queueadd_back(t_node *node, t_queue *queue);
void	ft_queueadd_back_num(int num, t_queue *queue);
void	ft_queueadd_front(t_node *node, t_queue *queue);
void	ft_queueadd_front_num(int num, t_queue *queue);
t_node	*ft_queuepop(t_queue *queue);
void	ft_queuedelone(t_queue *queue);
void	ft_queuedelall(t_queue *queue);

#endif
