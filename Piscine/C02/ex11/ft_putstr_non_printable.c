/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 18:00:05 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/10 19:49:57 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_not_printable(char c)
{
	int	resul;

	resul = 1;
	if (' ' <= c && c <= '~')
		resul = 0;
	return (resul);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	to_hex(int num)
{
	char	*hex;

	hex = "0123456789abcdef";
	ft_putchar('\\');
	ft_putchar(hex[num / 16]);
	ft_putchar(hex[num % 16]);
}

void	ft_putstr_non_printable(char *str)
{	
	int		cont;

	cont = 0;
	while (str[cont] != '\0')
	{
		if (ft_is_not_printable(str[cont]))
		{
			to_hex(str[cont]);
		}
		else
			write(1, &str[cont], 1);
		cont++;
	}
}
