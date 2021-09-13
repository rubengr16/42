/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:06:52 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/21 00:56:50 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_find_next_prime(int nb);

int	main(void)
{
	printf("+Input: 0\n-Output: %d", ft_find_next_prime(0));
	printf("\n=============================================");
	printf("\n+Input: 1\n-Output: %d", ft_find_next_prime(1));
	printf("\n=============================================");
	printf("\n+Input: 54\n-Output: %d", ft_find_next_prime(54));
	printf("\n=============================================");
	printf("\n+Input: 29385939\n-Output: %d", ft_find_next_prime(29385939));
	printf("\n=============================================");
	printf("\n+Input: 13\n-Output: %d", ft_find_next_prime(13));
	printf("\n=============================================");
	printf("\n+Input: 27\n-Output: %d", ft_find_next_prime(27));
	printf("\n=============================================");
	printf("\n+Input: -2147483648\n-Output: %d", ft_find_next_prime(-2147483648));
}
