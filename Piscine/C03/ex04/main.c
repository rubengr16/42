/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 10:46:20 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/16 11:24:37 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strstr(char *str, char *to_find);

int	main(void)
{
	char	*str = "Me, myself and I";
	char	*to_find = "self";
	printf("str = %s, to_find = %s\n", str, to_find);
	printf("string.h = %s\n", strstr(str, to_find));
	printf("mine = %s\n", ft_strstr(str, to_find));	
	printf("\n ====================================\n");
	to_find = "Me,";
	printf("str = %s, to_find = %s\n", str, to_find);
	printf("string.h = %s\n", strstr(str, to_find));
	printf("mine = %s\n", ft_strstr(str, to_find));	
	printf("\n ====================================\n");
	to_find = "asdfghj";
	printf("str = %s, to_find = %s\n", str, to_find);
	printf("str = %s, to_find = %s\n", str, to_find);
	printf("string.h = %s\n", strstr(str, to_find));
	printf("mine = %s\n", ft_strstr(str, to_find));
	printf("\n ====================================\n");
	to_find = "\0";
	printf("str = %s, to_find = %s\n", str, to_find);
	printf("str = %s, to_find = %s\n", str, to_find);
	printf("string.h = %s\n", strstr(str, to_find));
	printf("mine = %s\n", ft_strstr(str, to_find));
}
