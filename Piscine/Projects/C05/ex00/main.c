/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 20:05:37 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/16 20:10:15 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb);

int	main(void)
{
	printf("!5 = %d\n", ft_iterative_factorial(5));
	printf("!10 = %d\n", ft_iterative_factorial(10));
	printf("!67 = %d\n", ft_iterative_factorial(67));
	printf("!0 = %d\n", ft_iterative_factorial(0));
	printf("!1 = %d\n", ft_iterative_factorial(1));
	printf("!-5 = %d\n", ft_iterative_factorial(-5));
}
