/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 09:42:49 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/10 12:15:26 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);

int	main(void)
{
	char	*st = "hello ruben";
	char	*cpy = NULL;
	char	str[20];

	cpy = str;
	printf("%s\n", st);
	cpy = ft_strncpy(cpy, st, 4);	
	printf("%s\n", st);
	printf("%s\n", cpy);

}
