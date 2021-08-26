/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 10:08:59 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/22 14:30:55 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void	ft_write_num(t_list *list, char *num)
{
	int	len;

	len = ft_strlen(num);
	while (len > 0 && *num)
	{
		if ((len == 1) || (len > 1 && *num != '0'))
		{
			if ((len % 3) != 2)
			{
				ft_putstr(ft_search_little(list, *num, 1));
				ft_putstr(" ");
				if ((len % 3) == 0)
					ft_putstr(ft_search_bigger(list, 3));
				else
					ft_putstr(ft_search_bigger(list, len));
			}
			else
				ft_putstr(ft_search_little(list, *num, 2));
			if (len != 1)
				ft_putstr(" ");
			len--;
			num++;
		}
	}
}
