/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:02:09 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/12 12:23:34 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n);

int	main(void)
{
	char	*st;
	char	*c;

	c = "hellaaaaaa";
	st = "hellaaaa";
	printf("%d", strncmp(c, st, 5));
	printf("%d", ft_strncmp(c, st, 5));
}
