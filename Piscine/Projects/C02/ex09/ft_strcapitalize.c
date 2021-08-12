/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 14:38:06 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/12 11:49:25 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	to_up(char c)
{
	return (c - 'a' + 'A');
}

char	to_low(char c)
{
	return (c - 'A' + 'a');
}

char	*ft_strcapitalize(char *str)
{
	int	cont;

	cont = 0;
	if ('a' <= str[cont] && str[cont] <= 'z')
		str[cont] = to_up(str[cont]);
	cont++;
	while (str[cont] != '\0')
	{
		if (!(('0' <= str[cont - 1] && str[cont - 1] <= '9')
				|| ('a' <= str[cont - 1] && str[cont - 1] <= 'z')
				|| ('A' <= str[cont - 1] && str[cont - 1] <= 'Z')))
		{
			if ('a' <= str[cont] && str[cont] <= 'z')
				str[cont] = to_up(str[cont]);
		}
		else
			if ('A' <= str[cont] && str[cont] <= 'Z')
				str[cont] = to_low(str[cont]);
		cont++;
	}
	return (str);
}
