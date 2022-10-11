/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:26:55 by rgallego          #+#    #+#             */
/*   Updated: 2022/10/11 20:17:41 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
 * receives a number and searchs if it is already inserted on the stack.
 * INPUT:	t_queue *queue, int nb
 * OUTPUT:	int	:	0	nb is not in the stack
 *					1	nb is already on the stack
 */
static int	nbrepeated(t_queue *queue, int nb)
{
	t_qnode	*aux;

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
 * receives an initialized queue and inserts the numbers contained on argv
 * doing the necessary tests in order to avoid non-numerical elements and
 * repeated numbers.
 * INPUT:	t_queue *queue, char **argv
 * OUTPUT:	void
 */
void	argtostack(t_queue *queue, char **argv)
{
	char	**set;
	int		nb;
	int		cnt;
	int		cnt_set;

	if (!argv)
		ft_error("Error. No argv.", STDERR_FILENO, ERR_USR);
	cnt = 0;
	while (argv[cnt])
	{
		set = ft_split(argv[cnt], ' ');
		if (!set)
			ft_error("Error. Split failed.", STDERR_FILENO, ERR_USR);
		cnt_set = 0;
		while (set[cnt_set])
		{
			nb = ft_atoi_err(set[cnt_set]);
			if (nbrepeated(queue, nb))
				ft_error("Error. Number repeated.", STDERR_FILENO, ERR_USR);
			(void)queueadd_back_num(queue, nb);
			cnt_set++;
		}
		ft_free_split(set);
		cnt++;
	}
}

void	push_swap_init(t_queue **a, t_queue **b, t_mvntslist **mvnts)
{
	*a = queueinit('a');
	if (!*a)
		ft_error("Error. Couldn't initialize a", STDOUT_FILENO, ERR_USR);
	*b = queueinit('b');
	if (!*b)
		ft_error("Error. Couldn't initialize b", STDOUT_FILENO, ERR_USR);
	*mvnts = mvntslistinit();
	if (!*mvnts)
		ft_error("Error. Couldn't initialize mvnts", STDOUT_FILENO, ERR_USR);
}

void	print_mvnts(t_mvntslist *mvnts)
{
	t_lnode	*aux;

	while (mvnts->n_elem)
	{
		aux = mvntslistpop(mvnts);
		ft_putendl_fd(aux->mvnt, STDOUT_FILENO);
		free(aux);
	}
	mvntslistdelall(mvnts);
}
