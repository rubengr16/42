/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:01:47 by rgallego          #+#    #+#             */
/*   Updated: 2023/02/22 14:24:28 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

static int	oposite_r(char *first_mvnt, char *current_mvnt)
{
	if (!ft_strncmp(first_mvnt, "ra", 2)
		&& !ft_strncmp(current_mvnt, "rb", 2))
		return (1);
	if (!ft_strncmp(first_mvnt, "rb", 2)
		&& !ft_strncmp(current_mvnt, "ra", 2))
		return (1);
	return (0);
}

static int	oposite_rr(char *first_mvnt, char *current_mvnt)
{
	if (!ft_strncmp(first_mvnt, "ra", 2)
		&& !ft_strncmp(current_mvnt, "rra", 3))
		return (1);
	if (!ft_strncmp(first_mvnt, "rb", 2)
		&& !ft_strncmp(current_mvnt, "rrb", 3))
		return (1);
	if (!ft_strncmp(first_mvnt, "rra", 3)
		&& !ft_strncmp(current_mvnt, "ra", 2))
		return (1);
	if (!ft_strncmp(first_mvnt, "rrb", 3)
		&& !ft_strncmp(current_mvnt, "rb", 2))
		return (1);
	if (!ft_strncmp(first_mvnt, "rr", 2)
		&& !ft_strncmp(current_mvnt, "rrr", 3))
		return (1);
	if (!ft_strncmp(first_mvnt, "rrr", 3)
		&& !ft_strncmp(current_mvnt, "rr", 2))
		return (1);
	return (0);
}

void	optimize_r(t_mvntslist *mvnts, t_lnode *first_r, int n_iter, int cnt)
{
	while (n_iter--)
	{
		if (!first_r && mvnts->head->mvnt[0] == 'r')
			first_r = mvnts->head;
		if (first_r && !ft_strncmp(mvnts->head->mvnt, first_r->mvnt, 2))
			cnt++;
		else if (cnt && oposite_r(first_r->mvnt, mvnts->head->mvnt))
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
	}
}

void	optimize_rr(t_mvntslist *mvnts, t_lnode *first_r, int n_iter, int cnt)
{
	while (n_iter--)
	{
		if (!first_r && mvnts->head->mvnt[0] == 'r')
			first_r = mvnts->head;
		if (first_r && !ft_strncmp(mvnts->head->mvnt, first_r->mvnt, 3))
			cnt++;
		else if (cnt && oposite_rr(first_r->mvnt, mvnts->head->mvnt))
		{
			if (cnt == 1)
				first_r = NULL;
			mvntslistdelone(mvnts);
			mvnts->head = mvnts->head->prvs;
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
	}
}
