/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvntslistdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:32:30 by rgallego          #+#    #+#             */
/*   Updated: 2022/10/11 18:23:58 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mvntslist.h"

/* function which deletes the first node of a mvntslist
 * INPUT: 	t_mvntslist *mvntslist
 * OUTPUT:	void
 */
void	mvntslistdelone(t_mvntslist *mvntslist)
{
	t_lnode	*aux;

	if (mvntslist->n_elem)
	{
		aux = mvntslistpop(mvntslist);
		free(aux->mvnt);
		free(aux);
	}
}

/* function which deletes a mvntslist
 * INPUT: 	t_mvntslist **mvntslist
 * OUTPUT:	void
 */
void	mvntslistdelall(t_mvntslist *mvntslist)
{
	if (!mvntslist)
		return ;
	while (mvntslist->n_elem)
		mvntslistdelone(mvntslist);
	mvntslist->head = NULL;
	free(mvntslist);
	mvntslist = NULL;
}
