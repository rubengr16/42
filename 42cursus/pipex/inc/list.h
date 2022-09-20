/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:19:13 by rgallego          #+#    #+#             */
/*   Updated: 2022/09/20 11:53:55 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stdlib.h>

typedef struct s_node
{
	char			*cmd;
	char			*flag;
	struct s_node	*next;
}	t_node;

typedef struct s_list
{
	int		n_elem;
	t_node	*head;
	t_node	*tail;
}	t_list;

/************************** LIST FUNCTIONS ********************************* */
t_list	*listinit(char c);
t_node	*newnode(char *cmd, char *flag);
void	listpush(t_list *list, t_node *node);
t_node	*listpush_cmd(t_list *list, char *cmd, char *flag);
t_node	*listpop(t_list *list);
void	listdelone(t_list *list);
void	listdelall(t_list *list);

#endif
