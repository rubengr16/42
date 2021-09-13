/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 11:41:10 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/12 11:19:21 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	alpha;

	alpha = 1;
	while (str[alpha - 1] && alpha)
	{
		if ('A' <= str[alpha - 1] && str[alpha - 1] <= 'Z')
			alpha++;
		else
			alpha = 0;
	}
	if (alpha)
		alpha = 1;
	return (alpha);
}
