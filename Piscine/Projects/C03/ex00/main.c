/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:02:09 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/11 17:33:30 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2);

int	main(void)
{
	char	*st;
	char	*c;

	c = "helloooooo";
	st = "hello";
	printf("%d\n", strcmp(c, st));
	printf("%d\n", ft_strcmp(c, st));
}
