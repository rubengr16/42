/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:55:48 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/10 14:22:06 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	to_up(char c)
{
	return (c - 'a' + 'A');
}

char	*ft_strupcase(char *str)
{
	char	*upstr;

	upstr = str;
	while (*upstr != '\0')
	{
		if ('a' <= *upstr && *upstr <= 'z')
			*upstr = to_up(*upstr);
		upstr++;
	}
	*upstr = '\0';
	return (str);
}
