/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:01:33 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/12 12:50:15 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strncat(char *dest, char *src, unsigned int n);

int	main(void)
{
	char	*str = "hello";
	char	str2[15];

	str2[0] = 'H';
	str2[1] = '\0';
	printf("%s", strncat(str2, str, 3));
	printf("%s", ft_strncat(str2, str, 3));
}
