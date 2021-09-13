/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:01:33 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/12 12:33:37 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strcat(char *dest, char *src);

int	main(void)
{
	char	*str = "hello";
	char	str2[15];

	str2[0] = 'H';
	str2[1] = '\0';
	printf("%s", strcat(str2, str));
	printf("%s", ft_strcat(str2, str));
}
