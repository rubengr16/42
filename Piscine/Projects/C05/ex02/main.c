/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 08:59:26 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/17 09:09:10 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_power(int nb, int power);

int	main(void)
{
	printf("+Input: nb = 10, power = 2\n");
	printf("-Output: result = %d\n", ft_iterative_power(10, 2));
	printf("===============================\n");
	printf("+Input: nb = 0, power = 0\n");
	printf("-Output: result = %d\n", ft_iterative_power(0, 0));
	printf("===============================\n");
	printf("+Input: nb = 2, power = 5\n");
	printf("-Output: result = %d\n", ft_iterative_power(2, 5));
	printf("===============================\n");
	printf("+Input: nb = -3, power = 3\n");
	printf("-Output: result = %d\n", ft_iterative_power(-3, 3));
	printf("===============================\n");
	printf("+Input: nb = -4, power = 4\n");
	printf("-Output: result = %d\n", ft_iterative_power(-4, 4));
}
