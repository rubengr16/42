/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:55:48 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/12 11:42:39 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	to_up(char c)
{
	return (c - 'a' + 'A');
}

char	*ft_strupcase(char *str)
{
	int	cont;

	cont = 0;
	while (str[cont])
	{
		if ('a' <= str[cont] && str[cont] <= 'z')
			str[cont] = to_up(str[cont]);
		cont++;
	}
	str[cont] = '\0';
	return (str);
}
