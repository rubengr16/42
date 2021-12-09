/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argtostack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:26:55 by rgallego          #+#    #+#             */
/*   Updated: 2021/12/09 14:49:24 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
 * function which receives a set of strings and tranforms each one to int and
 * inserts one by one each number to the stack.
 * INPUT:	t_queue *queue, char **set
 * OUTPUT:	void
 */
static void	ft_settostack(t_queue *queue, char	**set)
{
	int	nb;
	int	cnt;

	if (set)
	{
		cnt = 0;
		while (cnt >= 0 && set[cnt])
		{
			nb = ft_atoi(set[cnt]);
			if ((!nb || nb == -1) && ft_strlen(set[cnt]) > 2)
			{
				ft_queuedelall(queue);
				cnt = -1;
			}
			else
			{
				ft_queueadd_front_num(queue, nb);
				cnt++;
			}
		}
	}
}

void	ft_argtostack(t_queue *queue, char **argv)
{
	char	**set;
	int		cnt;
	
	if (argv)
	{
		cnt = 0;
		while (cnt >= 0 && argv[cnt])
		{
			set = ft_split(argv[cnt], ' ');
			if (set)
			{
				ft_settostack(queue, set);
				cnt++;
			}
			else
			{
				ft_queuedelall(queue);
				cnt = -1;
			}
		}
	}
}
