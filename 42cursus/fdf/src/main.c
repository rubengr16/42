/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:59:49 by rgallego          #+#    #+#             */
/*   Updated: 2022/02/21 15:30:22 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	int	fdin;

	if (argc != 2)
		error_msg(NULL);
	fdin = open(argv[FILE], O_RDONLY);
	if (fdin < 0)
		error_msg(argv[FILE]);
	return (0);
}
