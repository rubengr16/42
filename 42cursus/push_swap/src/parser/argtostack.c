/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argtostack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:26:55 by rgallego          #+#    #+#             */
/*   Updated: 2022/08/22 20:42:31 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
 * receives a number and searchs if it is already inserted on the stack.
 * INPUT:	t_queue *queue, int nb
 * OUTPUT:	int	:	0	nb is not in the stack
 *					1	nb is already on the stack
 */

static int	nbrepeated(t_queue *queue, int nb)
{
	t_node	*aux;

	if (!queue || !queue->n_elem)
		return (0);
	if (queue->head->num == nb)
		return (1);
	aux = queue->head->next;
	while (aux != queue->head && aux->num != nb)
		aux = aux->next;
	if (aux->num == nb)
		return (1);
	return (0);
}

/*
 * receives a set of strings and tranforms each one to int and inserts one by 
 * one each number to the stack. For each number test that the atoi has been 
 * executed correctly and that it is not repeated on the stack.
 * INPUT:	t_queue *queue, char **set
 * OUTPUT:	int	:	-1	error ocurred
 *					N > 0	okay
 */
static int	settostack(t_queue *queue, char	**set)
{
	int	nb;
	int	cnt;

	if (!set)
		return (0);
	cnt = 0;
	while (set[cnt])
	{
		nb = ft_atoi(set[cnt]);
		if (ft_atoi_check(nb, set[cnt]) || nbrepeated(queue, nb))
			return (-1);
		queueadd_back_num(queue, nb);
		cnt++;
	}
	return (cnt);
}

/*
 * receives an initialized queue and inserts the numbers contained on argv
 * doing the necessary tests in order to avoid non-numerical elements and
 * repeated numbers.
 * INPUT:	t_queue *queue, char **argv
 * OUTPUT:	void	
 */

void	argtostack(t_queue **queue, char **argv)
{
	char	**set;
	int		cnt;

	if (!argv)
		return ;
	cnt = 0;
	while (argv[cnt])
	{
		set = ft_split(argv[cnt], ' ');
		if (!set || settostack(*queue, set) < 0)
		{
			queuedelall(queue);
			return ;
		}
		cnt++;
	}
	ft_free_split(set);
}
