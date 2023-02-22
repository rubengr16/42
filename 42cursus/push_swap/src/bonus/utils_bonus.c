/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:26:55 by rgallego          #+#    #+#             */
/*   Updated: 2023/02/22 18:03:25 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

void	argtostack_bonus(t_queue *queue, char **argv)
{
	char	**set;
	int		nb;
	int		cnt;
	int		cnt_set;

	if (!argv)
		ft_error("Error", STDERR_FILENO, ERR_USR);
	cnt = 0;
	while (argv[cnt])
	{
		set = ft_split(argv[cnt], ' ');
		if (!set)
			ft_error("Error", STDERR_FILENO, ERR_USR);
		cnt_set = 0;
		while (set[cnt_set])
		{
			nb = ft_atoi_just_err(set[cnt_set]);
			if (nbrepeated(queue, nb))
				ft_error("Error", STDERR_FILENO, ERR_USR);
			(void)queueadd_back_num(queue, nb);
			cnt_set++;
		}
		ft_free_split(set);
		cnt++;
	}
}

void	push_swap_init_bonus(t_push_swap_bonus *push_swap)
{
	push_swap->a = queueinit('a');
	if (!push_swap->a)
		ft_error("Error", STDOUT_FILENO, ERR_USR);
	push_swap->b = queueinit('b');
	if (!push_swap->b)
		ft_error("Error", STDOUT_FILENO, ERR_USR);
}

int	execute_mvnt(t_push_swap_bonus push_swap, char *mvnt, int len)
{
	if (!ft_strncmp(mvnt, "pa", len))
		return (push_queue(push_swap.a, push_swap.b));
	if (!ft_strncmp(mvnt, "pb", len))
		return (push_queue(push_swap.b, push_swap.a));
	if (!ft_strncmp(mvnt, "sa", len))
		return (swap_queue(push_swap.a));
	if (!ft_strncmp(mvnt, "sb", len))
		return (swap_queue(push_swap.b));
	if (!ft_strncmp(mvnt, "ss", len))
		return (swap_queue(push_swap.a) * swap_queue(push_swap.b));
	if (!ft_strncmp(mvnt, "ra", len))
		return (rotate_queue(push_swap.a));
	if (!ft_strncmp(mvnt, "rb", len))
		return (rotate_queue(push_swap.b));
	if (!ft_strncmp(mvnt, "rr", len))
		return (rotate_queue(push_swap.a) * rotate_queue(push_swap.b));
	if (!ft_strncmp(mvnt, "rra", len))
		return (rev_rotate_queue(push_swap.a));
	if (!ft_strncmp(mvnt, "rrb", len))
		return (rev_rotate_queue(push_swap.b));
	if (!ft_strncmp(mvnt, "rrr", len))
		return (rev_rotate_queue(push_swap.a) * rev_rotate_queue(push_swap.b));
	return (0);
}
