/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdslist.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:19:13 by rgallego          #+#    #+#             */
/*   Updated: 2022/09/20 11:53:55 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMDSLIST_H
# define CMDSLIST_H

# include <stdlib.h>
# include "libft.h"

/*************************** COMMAND STRUCTURE ****************************** */
# define CMD 0
# define FLAG 1

/************************** CMDSLIST STRUCTURE ****************************** */
typedef struct s_node
{
	char			**cmd_flag;
	struct s_node	*next;
}	t_node;

typedef struct s_cmdslist
{
	int		n_elem;
	t_node	*head;
	t_node	*tail;
}	t_cmdslist;

/************************* CMDSLIST FUNCTIONS ****************************** */
t_cmdslist	*cmdslistinit(void);
t_node		*newnode(char **cmd_flag);
void		cmdslistpush(t_cmdslist *list, t_node *node);
t_node		*cmdslistpush_cmd(t_cmdslist *list, char **cmd_flag);
t_node		*cmdslistpop(t_cmdslist *list);
void		cmdslistdelone(t_cmdslist *list);
void		cmdslistdelall(t_cmdslist *list);

#endif
