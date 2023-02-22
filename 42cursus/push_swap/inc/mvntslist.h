/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvntslist.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:55:24 by rgallego          #+#    #+#             */
/*   Updated: 2023/02/22 12:45:07 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MVNTSLIST_H
# define MVNTSLIST_H

# include <stdlib.h>

typedef struct s_lnode
{
	char			*mvnt;
	struct s_lnode	*next;
	struct s_lnode	*prvs;
}	t_lnode;

typedef struct s_mvntslist
{
	int		n_elem;
	t_lnode	*head;
}	t_mvntslist;

/************************** BASIC LIST FUNCTIONS **************************** */
t_mvntslist	*mvntslistinit(void);
t_lnode		*newlnode(char *mvnt);
void		mvntslistadd_back(t_mvntslist *mvntslist, t_lnode *node);
t_lnode		*mvntslistadd_back_mvnt(t_mvntslist *mvntslist, char *mvnt);
void		mvntslistadd_front(t_mvntslist *mvntslist, t_lnode *node);
t_lnode		*mvntslistadd_front_mvnt(t_mvntslist *mvntslist, char *mvnt);
t_lnode		*mvntslistpop(t_mvntslist *mvntslist);
void		mvntslistdelone(t_mvntslist *mvntslist);
void		mvntslistdelall(t_mvntslist *mvntslist);

#endif
