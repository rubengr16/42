/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvntslistinit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:47:23 by rgallego          #+#    #+#             */
/*   Updated: 2022/10/11 18:24:11 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mvntslist.h"

/*
 * reserves memory using malloc and initializes its values head and n_elem to
 * NULL and 0 respectively, meanwhile, id is set to the given char
 * INPUT:	void
 * OUTPUT:	t_mvntslist *mvntslist
 */
t_mvntslist	*mvntslistinit(void)
{
	t_mvntslist	*mvntslist;

	mvntslist = malloc(sizeof(t_mvntslist));
	if (!mvntslist)
		return (NULL);
	mvntslist->head = NULL;
	mvntslist->n_elem = 0;
	return (mvntslist);
}
