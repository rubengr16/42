/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 09:42:49 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/13 11:03:35 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

//char	*ft_strncpy(char *dest, char *src, unsigned int n);

int	main(void)
{
	char	*st = "hello";
	char	*cpy;
//	char	*cpy2;
	char	str[5];

	cpy = str;
	/*cpy2 = str,
	printf("%s\n", st);
//	cpy = ft_strncpy(cpy, st, 15);	
	printf("%s\n", st);
	printf("%s\n", cpy);
	printf("%s\n", st);*/
	cpy = strncpy(cpy, st, 6);	
	printf("%s\n", st);
	if (!st[4])
		printf("he");
	printf("%s\n", cpy);
	if (!cpy[4])
		printf("he");


}
