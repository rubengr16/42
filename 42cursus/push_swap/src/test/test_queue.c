/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_queue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:22:18 by rgallego          #+#    #+#             */
/*   Updated: 2021/12/08 19:55:08 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "queue.h"
#include "mvmnts.h"
#include "parser.h"

/*
 * TEST FOR MY QUEUE
 */

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		if (ft_setisdigit(&argv[1]))
			printf("Yay, u entered all digits\n");
		else
			printf("Nay, bad input\n");
	}
	else
		printf("More arguments please\n");
	return (0);
}
