/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:09:01 by rgallego          #+#    #+#             */
/*   Updated: 2023/02/22 14:22:56 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

static int	oposite_p(char *first_mvnt, char *current_mvnt)
{
	if (!ft_strncmp(first_mvnt, "pa", 2)
		&& !ft_strncmp(current_mvnt, "pb", 2))
		return (1);
	if (!ft_strncmp(first_mvnt, "pb", 2)
		&& !ft_strncmp(current_mvnt, "pa", 2))
		return (1);
	return (0);
}

void	optimize_p(t_mvntslist *mvnts, t_lnode *first_p, int n_iter, int cnt)
{
	while (n_iter--)
	{
		if (!first_p && mvnts->head->mvnt[0] == 'p')
			first_p = mvnts->head;
		if (first_p && !ft_strncmp(mvnts->head->mvnt, first_p->mvnt, 2))
			cnt++;
		else if (cnt && oposite_p(first_p->mvnt, mvnts->head->mvnt))
		{
			if (cnt == 1)
				first_p = NULL;
			mvntslistdelone(mvnts);
			mvnts->head = mvnts->head->prvs;
			mvntslistdelone(mvnts);
			mvnts->head = mvnts->head->prvs;
			cnt--;
		}
		else
		{
			first_p = NULL;
			cnt = 0;
		}
		if (mvnts->head)
			mvnts->head = mvnts->head->next;
	}
}

void	optimizer(t_mvntslist *mvnts)
{
	optimize_rr(mvnts, NULL, mvnts->n_elem, 0);
	optimize_p(mvnts, NULL, mvnts->n_elem, 0);
	optimize_r(mvnts, NULL, mvnts->n_elem, 0);
}
