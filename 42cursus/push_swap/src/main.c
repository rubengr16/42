/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:22:18 by rgallego          #+#    #+#             */
/*   Updated: 2022/12/23 17:44:53 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "utils.h"
#include "algorithm.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_push_swap	push_swap;


	if (argc == 1)
		ft_error("Error. Enter more than 1 argument.", STDERR_FILENO, ERR_USR);
	push_swap_init(&push_swap);
	argtostack(push_swap.a, &argv[1]);
	print_queue(*push_swap.a);
	if (!is_sorted(push_swap.a))
		merge_mean(push_swap);
	queuedelall(push_swap.a);
	queuedelall(push_swap.b);
	stackdelall(push_swap.a_means);
	stackdelall(push_swap.b_means);
	print_mvnts(push_swap.mvnts);
	// system("leaks push_swap");
	return (0);
}
