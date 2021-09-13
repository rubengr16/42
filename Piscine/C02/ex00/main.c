/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 09:42:49 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/12 10:46:52 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strcpy(char *dest, char *src);

int	main(void)
{
	char	*st = "12345678901234567";
	char	*cpy;
	char	*cpy2;
	char	str[20];
	char	str2[20];
	
	cpy = str;
	cpy2 = str2;
	printf("%s\n", st);
	ft_strcpy(cpy, st);	
	printf("%s\n", st);
	printf("%s\n", cpy);
	printf("%s\n", st);
	strcpy(cpy2, st);	
	printf("%s\n", st);
	printf("%s\n", cpy2);
	return (0);
}
