/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 09:15:52 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/17 09:21:19 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_fibonacci(int index);

int	main(void)
{
	printf("+Input: fib(0)\n-Output: %d\n", ft_fibonacci(0));
	printf("==================================\n");
	printf("+Input: fib(1)\n-Output: %d\n", ft_fibonacci(1));
	printf("==================================\n");
	printf("+Input: fib(2)\n-Output: %d\n", ft_fibonacci(2));
	printf("==================================\n");
	printf("+Input: fib(6)\n-Output: %d\n", ft_fibonacci(6));
	printf("==================================\n");
	printf("+Input: fib(25)\n-Output: %d\n", ft_fibonacci(25));
	printf("==================================\n");
	printf("+Input: fib(40)\n-Output: %d\n", ft_fibonacci(40));
}
