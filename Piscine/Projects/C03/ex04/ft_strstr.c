/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 12:56:49 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/16 11:40:29 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*found;
	int		cont_str;
	int		cont_find;

	cont_str = 0;
	found = 0;
	while (str[cont_str] && !found)
	{
		cont_find = 0;
		if (str[cont_str] == to_find[cont_find] || !to_find[cont_find])
		{
			found = &str[cont_str];
			while (str[cont_str] == to_find[cont_find]
				&& str[cont_str] && to_find[cont_find])
			{
				cont_str++;
				cont_find++;
			}
			if (to_find[cont_find])
				found = 0;
			cont_str -= cont_find;
		}
		cont_str++;
	}
	return (found);
}
