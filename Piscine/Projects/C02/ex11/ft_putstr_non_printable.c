/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 18:00:05 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/10 19:03:19 by rgallego         ###   ########.fr       */
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

char	dec_to_hex(int num)
{
	if (num < 10)
		num = num + '0';
	else
		num = (num % 10) + 'a';
	return (num);
}

void	to_hex(int num, char *hex)
{
	char	aux[3];
	int		cont;
	int		aux_cont;

	cont = 0;
	while (num > 16)
	{
		aux[cont] = dec_to_hex(num % 16);
		num /= 16;
		cont++;
	}
	aux[cont] = dec_to_hex(num);
	hex[0] = '\\';
	aux_cont = 1;
	while (aux_cont <= cont)
	{
		hex[4 - cont] = aux[cont];
		aux_cont++;
	}
	hex[aux_cont + 1] = '\0';
}

void	print_hex(char *str)
{
	char	*aux;

	aux = str;
	while (*aux != '\0')
	{
		write(1, aux, 1);
		aux++;
	}
}

void	ft_putstr_non_printable(char *str)
{
	int		chrnbr;
	int		cont;
	char	hex[4];

	cont = 0;
	while (str[cont] != '\0')
	{
		if (ft_is_not_printable(str[cont]))
		{
			chrnbr = str[cont];
			to_hex(chrnbr, hex);
			print_hex(hex);
		}
		else
			write(1, &str[cont], 1);
		cont++;
	}
}
