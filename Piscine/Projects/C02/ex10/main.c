/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:00:31 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/10 16:55:44 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

int	main(void)
{
	char	str[] = "hello, world";
	char	dest[5];

	printf("%s\n", str);
	printf("%d\n", ft_strlcpy(dest, str, 4));
	printf("%s", dest);
	return (0);
}
