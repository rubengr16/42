/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 13:01:48 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/17 10:33:02 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_atoi_base(char *str, char *base);

int	main(void)
{
	printf("***### BASE = 0123456789 ###***\n");
	printf("%d, entered = %s\n", ft_atoi_base("--45", "0123456789"), "--45");
	printf("======================================\n");
	printf("%d, entered = %s\n", ft_atoi_base("1234567", "0123456789"),"1234567");
	printf("======================================\n");
	printf("%d, entered = %s\n", ft_atoi_base("  ---+--+1234ab5d6d7", "0123456789"), "  ---+--+1234ab5d6d7");
	printf("======================================\n");
	printf("%d, entered = %s\n", ft_atoi_base("sdfghj", "0123456789"), "sdfghj");
	printf("======================================\n");
	printf("%d, entered = %s\n", ft_atoi_base("-2147483648", "0123456789"), "-2147483648");
	
	printf("\n\n***### BASE = 01 ###***\n");
	printf("%d, entered = %s\n", ft_atoi_base("--45", "01"), "--45");
	printf("======================================\n");
	printf("%d, entered = %s\n", ft_atoi_base("10101", "01"),"10101");
	printf("======================================\n");
	printf("%d, entered = %s\n", ft_atoi_base("  ---+--+11101ab5d6d7", "01"), "  ---+--+11101ab5d6d7");
	printf("======================================\n");
	printf("%d, entered = %s\n", ft_atoi_base("sdfghj", "01"), "sdfghj");
	printf("======================================\n");
	printf("%d, entered = %s\n", ft_atoi_base("-1111111111", "01"), "-1111111111");
	
	printf("\n\n***### BASE = 0123456789ABCDEF ###***\n");
	printf("%d, entered = %s\n", ft_atoi_base("--45", "0123456789ABCDEF"), "--45");
	printf("======================================\n");
	printf("%d, entered = %s\n", ft_atoi_base("12ABCDE", "0123456789ABCDEF" ),"12ABCDE");
	printf("======================================\n");
	printf("%d, entered = %s\n", ft_atoi_base("  ---+--+1234AB5d6d7", "0123456789ABCDEF"), "  ---+--+1234AB5d6d7");
	printf("======================================\n");
	printf("%d, entered = %s\n", ft_atoi_base("sdfghj", "0123456789ABCDEF"), "sdfghj");
	printf("======================================\n");
	printf("%d, entered = %s\n", ft_atoi_base("-214asd98A", "0123456789ABCDEF"), "-214asd98A");

	printf("\n\n***### BASE = poneyvif ###***\n");
	printf("%d, entered = %s\n", ft_atoi_base("--45", "poneyvif"), "--45");
	printf("======================================\n");
	printf("%d, entered = %s\n", ft_atoi_base("enf", "poneyvif" ),"enf");
	printf("======================================\n");
	printf("%d, entered = %s\n", ft_atoi_base("  ---+--+ponfivdAB5d6d7", "poneyvif"), "  ---+--+ponfivdAB5d6d7");
	printf("======================================\n");
	printf("%d, entered = %s\n", ft_atoi_base("sdfghj", "poneyvif"), "sdfghj");
	printf("======================================\n");
	printf("%d, entered = %s\n", ft_atoi_base("-ivfpo", "poneyvif"), "-ivfpo");
}
