/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:00:31 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/13 13:08:19 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

int	main(void)
{
	char	str[] = "asdfghjklasdfghjghsjksdfgshjdfgshjdfghdfhgjdksddifdfg\nrtyu";
	char	dest[7];

	dest[0] = 'R';
	dest[1] = 'u';
	printf("%s\n", str);
	printf("%lu\n", strlcpy(dest, str, 7));
	printf("%s\n", dest);
	printf("%s\n", str);
	printf("%d\n", ft_strlcpy(dest, str, 7));
	printf("%s\n", dest);
	return (0);
}
