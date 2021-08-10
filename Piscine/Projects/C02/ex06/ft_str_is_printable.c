/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 11:41:10 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/10 12:49:35 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	printable;

	printable = 1;
	if (*str == '\0')
		printable = 0;
	while (str[printable - 1] != '\0' && printable)
	{
		if ('~' > str[printable - 1] && str[printable - 1] > ' ')
			printable++;
		else
			printable = 0;
	}
	if (printable)
		printable = 1;
	return (printable);
}
