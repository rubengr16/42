/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:01:33 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/16 11:58:21 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strlcat(char *dest, char *src, unsigned int n);

int	main(void)
{
	char	*str = "hello";
	char	dest[15];

	dest[0] = 'H';
	dest[1] = 'o';
	dest[2] = '\0';
	printf("return = %lu, string.h = %s\n", strlcat(dest, str, 3), dest);
	dest[0] = 'H';
	dest[1] = 'o';
	dest[2] = '\0';
	printf("return = %d, mine = %s\n", ft_strlcat(dest, str, 3), dest);
	printf("\n=====================================\n");
	dest[0] = '\0';
	printf("return = %lu, string.h = %s\n", strlcat(dest, str, 3), dest);
	dest[0] = '\0';
	printf("return = %d, mine = %s\n", ft_strlcat(dest, str, 3), dest);
	printf("\n=====================================\n");
	str = "";;
	dest[0] = 'H';
	dest[1] = 'o';
	dest[2] = '\0';
	printf("return = %lu, string.h = %s\n", strlcat(dest, str, 3), dest);
	dest[0] = 'H';
	dest[1] = 'o';
	dest[2] = '\0';
	printf("return = %d, mine = %s\n", ft_strlcat(dest, str, 3), dest);

}
