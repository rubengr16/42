/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:55:24 by rgallego          #+#    #+#             */
/*   Updated: 2022/10/11 15:20:05 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stdlib.h>

typedef struct s_lnode
{
	char			*mvnt;
	struct s_lnode	*next;
	struct s_lnode	*prvs;
}	t_lnode;

typedef struct s_list
{
	int		n_elem;
	t_lnode	*head;
}	t_list;

/************************** BASIC LIST FUNCTIONS **************************** */
t_list	*listinit(void);
t_lnode	*newlnode(char *mvnt);
void	listadd_back(t_list *list, t_lnode *node);
t_lnode	*listadd_back_mvnt(t_list *list, char *mvnt);
void	listadd_front(t_list *list, t_lnode *node);
t_lnode	*listadd_front_mvnt(t_list *list, char *mvnt);
t_lnode	*listpop(t_list *list);
void	listdelone(t_list *list);
void	listdelall(t_list *list);

#endif
