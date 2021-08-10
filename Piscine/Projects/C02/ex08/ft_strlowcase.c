/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdowncase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:55:48 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/10 14:31:19 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	to_low(char c)
{
	return (c - 'A' + 'a');
}

char	*ft_strlowcase(char *str)
{
	char	*lowstr;

	lowstr = str;
	while (*lowstr != '\0')
	{
		if ('A' <= *lowstr && *lowstr <= 'Z')
			*lowstr = to_low(*lowstr);
		lowstr++;
	}
	*lowstr = '\0';
	return (str);
}
