/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argtostack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:26:55 by rgallego          #+#    #+#             */
/*   Updated: 2021/12/13 00:33:39 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	ft_nbrepeated(t_queue *queue, int nb)
{
	t_node	*aux;

	if (queue && queue->n_elem)
	{
		if (queue->head->num != nb && queue->n_elem > 1)
		{
			aux = queue->head->next;
			while (aux != queue->head && aux->num != nb)
				aux = aux->next;
			if (aux->num == nb)
				return (1);
		}
		else if (queue->head->num == nb)
			return (1);
		else
			return (0);
	}
	return (0);
}

/*
 * function which receives a set of strings and tranforms each one to int and
 * inserts one by one each number to the stack.
 * INPUT:	t_queue *queue, char **set
 * OUTPUT:	int	:	-1	error ocurred
 *					N > 0	okay
 */
static int	ft_settostack(t_queue *queue, char	**set)
{
	int	nb;
	int	cnt;

	cnt = 0;
	if (set)
	{
		while (cnt >= 0 && set[cnt])
		{
			nb = ft_atoi(set[cnt]);
			if (((!nb || nb == -1) && ft_strlen(set[cnt]) > 2) ||
				ft_nbrepeated(queue, nb))
				cnt = -1;
			else
			{
				ft_queueadd_back_num(queue, nb);
				cnt++;
			}
		}
	}
	return (cnt);
}

void	ft_argtostack(t_queue **queue, char **argv)
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
				if (ft_settostack(*queue, set) >= 0)
					cnt++;
				else
					cnt = -1;
			}
			else
				cnt = -1;
		}
		if (cnt == -1)
			ft_queuedelall(queue);
	}
}
