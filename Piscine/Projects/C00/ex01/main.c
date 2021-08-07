/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 12:39:08 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/05 12:59:02 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void 	ft_print_alphabet(void)
{
	char	c;

	c = 'a';
	while ('a' <= c && c <= 'z')
	{
		write(1, &c, 1);
		c++;
	}
}

int 	main(void)
{
	ft_print_alphabet();
	return (0);
}
