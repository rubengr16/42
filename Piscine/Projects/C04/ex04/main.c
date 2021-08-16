/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 13:01:48 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/16 19:41:11 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	ft_putnbr_base(int nbr, char *str);

int	main(void)
{
	printf("Input: num = 168, base = 01\n"),
	ft_putnbr_base(168, "01");
	printf("\n======================================\n");
	printf("Input: num = 168, base = 0123456789\n");
	ft_putnbr_base(168, "0123456789");
	printf("\n======================================\n");
	printf("Input: num = 168, base = 0123456789ABCDEF\n");
	ft_putnbr_base(168, "0123456789ABCDEF");
	printf("\n======================================\n");
	printf("Input: num = 168, base = poneyvif\n");
	ft_putnbr_base(168, "poneyvif");
	printf("\n======================================\n");
	printf("Input: num = 168, base = po-neyvif\n");
	ft_putnbr_base(168, "po-neyvif");
	printf("\n======================================\n");
	printf("Input: num = 168, base = po8n8\n");
	ft_putnbr_base(168, "po8n8");
	printf("\n======================================\n");
	printf("Input: num = 168, base = \n");
	ft_putnbr_base(168, "");
	printf("\n======================================\n");
	printf("Input: num = 168, base = p\n");
	ft_putnbr_base(168, "p");
	printf("\n======================================\n");
	printf("Input: num = 168, base = po+neyvif\n");
	ft_putnbr_base(168, "po+neyvif");




}
