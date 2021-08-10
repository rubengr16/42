/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 09:42:49 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/10 12:15:14 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcpy(char *dest, char *src);

int	main(void)
{
	char	*st = "hello ruben";
	char	*cpy;
	char	str[20];
	
	cpy = str;
	printf("%s\n", st);
	cpy = ft_strcpy(cpy, st);	
	printf("%s\n", st);
	printf("%s\n", cpy);
}
