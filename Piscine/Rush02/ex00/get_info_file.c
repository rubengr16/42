/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugonzal <jugonzal@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 16:02:27 by jugonzal          #+#    #+#             */
/*   Updated: 2021/08/22 14:37:17 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct.h"

char	*ft_trim(char *str)
{
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t'
			|| *str == '\v' || *str == '\f' || *str == '\r'))
		str++;
	if (*str && *str == ':')
		str++;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t'
			|| *str == '\v' || *str == '\f' || *str == '\r'))
		str++;
	return (str);
}

int	ft_strlen2(char *str)
{
	int	len;

	len = 0;
	while (str[len] && (str[len] != ' ' && str[len] != '\n'
			&& str[len] != '\t' && str[len] != '\v' && str[len] != '\f'
			&& str[len] != '\r' && str[len] != ':'))
		len++;
	return (len);
}

int	ft_strlen3(char *str)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	return (len);
}

void	set_info(t_list *list, char *str)
{
	int		len2;
	int		len3;
	char	*id;
	char	*nb_str;

	while (*str)
	{
		len2 = ft_strlen2(str);
		id = malloc(sizeof(char) * (len2 + 1));
		if (id)
		{
			str = ft_strncpy(id, str, len2);
			str = ft_trim(str);
			len3 = ft_strlen3(str);
			nb_str = malloc(sizeof(char) * (len3 + 1));
			if (nb_str)
			{
				str = ft_strncpy(nb_str, str, len3);
				str++;
				ft_insert(list, id, nb_str, len2);
			}
		}
	}
}
