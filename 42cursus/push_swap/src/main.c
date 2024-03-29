/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:22:18 by rgallego          #+#    #+#             */
/*   Updated: 2023/02/23 09:51:40 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"
#include "algorithm.h"

int	main(int argc, char **argv)
{
	t_push_swap	push_swap;

	if (argc == 1)
		ft_error("Error. Enter more than 1 argument.", STDERR_FILENO, ERR_USR);
	push_swap_init(&push_swap);
	argtostack(push_swap.a, &argv[1]);
	if (!sorted(push_swap.a))
		merge_mdn(push_swap);
	queuedelall(push_swap.a);
	queuedelall(push_swap.b);
	stackdelall(push_swap.a_mdn);
	stackdelall(push_swap.b_mdn);
	print_mvnts(push_swap.mvnts);
	return (0);
}
