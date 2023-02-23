/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:22:18 by rgallego          #+#    #+#             */
/*   Updated: 2023/02/23 10:07:14 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"
#include "utils_bonus.h"

int	main(int argc, char **argv)
{
	t_push_swap_bonus	push_swap;
	char				*mvnt;

	if (argc == 1)
		return (0);
	push_swap_init_bonus(&push_swap);
	argtostack_bonus(push_swap.a, &argv[1]);
	mvnt = get_next_line(STDIN_FILENO);
	while (mvnt)
	{
		if (!execute_mvnt(push_swap, mvnt, ft_strlen(mvnt) - 1))
			ft_error("Error", STDERR_FILENO, ERR_USR);
		free(mvnt);
		mvnt = get_next_line(STDIN_FILENO);
	}
	if (sorted(push_swap.a))
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
	queuedelall(push_swap.a);
	queuedelall(push_swap.b);
	return (0);
}
