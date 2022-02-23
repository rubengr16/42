/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:09:31 by rgallego          #+#    #+#             */
/*   Updated: 2022/02/23 18:21:42 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error_msg(char	*str)
{
	if (str)
		perror(str);
	else
		ft_putendl_fd("Please, respect the structure: ./fdf <file.fdf>", \
				STDERR_FILENO);
	exit(errno);
}
