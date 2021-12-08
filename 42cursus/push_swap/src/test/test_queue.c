/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_queue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:22:18 by rgallego          #+#    #+#             */
/*   Updated: 2021/12/08 14:54:07 by rgallego         ###   ########.fr       */
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
		if (ft_setisdigit(argv))
			printf("Yay, u entered all digits");
		else
			printf("Nay, bad input");
	}
	else
		printf("More arguments please");
	return (0);
}
