/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:09:01 by rgallego          #+#    #+#             */
/*   Updated: 2023/01/31 14:18:15 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

 static int	is_oposite_r(char *first_mvnt, char *current_mvnt)
 {
	if (!ft_strncmp(first_mvnt, "ra", 2)
		&& !ft_strncmp(current_mvnt, "rb", 2))
		return (1);
	if (!ft_strncmp(first_mvnt, "rb", 2)
		&& !ft_strncmp(current_mvnt, "ra", 2))
		return (1);
	return (0);
 }

void	optimizer(t_mvntslist *mvnts)
{
	t_lnode		*first_r;
	int			cnt;
	int			n_iter;

	first_r = NULL;
	cnt = 0;
	n_iter = mvnts->n_elem;
	while (n_iter)
	{
		if (!first_r && (!ft_strncmp(mvnts->head->mvnt, "ra", 2)
			|| !ft_strncmp(mvnts->head->mvnt, "rb", 2)))
			first_r = mvnts->head;
		if (first_r && !ft_strncmp(mvnts->head->mvnt, first_r->mvnt, 2))
			cnt++;
		else if (cnt && is_oposite_r(first_r->mvnt, mvnts->head->mvnt))
		{
			first_r->mvnt[1] = 'r';
			first_r = first_r->next;
			if (cnt == 1)
				first_r = NULL;
			mvntslistdelone(mvnts);
			mvnts->head = mvnts->head->prvs;
			cnt--;
		}
		else
		{
			first_r = NULL;
			cnt = 0;
		}
		mvnts->head = mvnts->head->next;
		n_iter--;
	}
}
