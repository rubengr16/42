/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdowncase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:55:48 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/12 11:46:20 by rgallego         ###   ########.fr       */
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
	while (*lowstr)
	{
		if ('A' <= *lowstr && *lowstr <= 'Z')
			*lowstr = to_low(*lowstr);
		lowstr++;
	}
	*lowstr = '\0';
	return (str);
}
