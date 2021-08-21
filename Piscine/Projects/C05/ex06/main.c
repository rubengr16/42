/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:06:52 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/20 11:32:53 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb);

int	main(void)
{
	printf("+Input: 0\n-Output: %d", ft_is_prime(0));
	printf("\n=============================================");
	printf("\n+Input: 1\n-Output: %d", ft_is_prime(1));
	printf("\n=============================================");
	printf("\n+Input: 21577\n-Output: %d", ft_is_prime(21577));
	printf("\n=============================================");
	printf("\n+Input: 101\n-Output: %d", ft_is_prime(103));
	printf("\n=============================================");
	printf("\n+Input: -2431\n-Output: %d", ft_is_prime(-2431));
	printf("\n=============================================");
	printf("\n+Input: -12\n-Output: %d", ft_is_prime(-12));
	printf("\n=============================================");
	printf("\n+Input: 2\n-Output: %d", ft_is_prime(2));
	printf("\n=============================================");
	printf("\n+Input: 2147483647\n-Output: %d", ft_is_prime(2147483647));
}
