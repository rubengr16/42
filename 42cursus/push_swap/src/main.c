/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:22:18 by rgallego          #+#    #+#             */
/*   Updated: 2022/10/11 23:15:36 by rgallego         ###   ########.fr       */
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
	push_swap_init(&push_swap.a, &push_swap.b, &push_swap.mvnts);
	argtostack(push_swap.a, &argv[1]);
	if (!is_sorted(push_swap.a))
		ft_mergesort(push_swap, (push_swap.a->n_elem / 2));
	queuedelall(push_swap.a);
	queuedelall(push_swap.b);
	print_mvnts(push_swap.mvnts);
	// system("leaks push_swap");
	return (0);
}
