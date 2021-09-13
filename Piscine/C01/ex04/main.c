/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 12:52:49 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/09 13:11:09 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int *a, int *b);

int	main(void)
{
	int	a;
	int	b;

	a = 19;
	b = 3;
	printf("a = %d, b = %d\n", a, b);
	ft_div_mod(&a, &b);
	printf("a = %d, b = %d", a, b);
}
