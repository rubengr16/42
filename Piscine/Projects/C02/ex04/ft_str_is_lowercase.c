/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 11:41:10 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/10 12:22:10 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	alpha;

	alpha = 1;
	while (str[alpha - 1] != '\0' && alpha)
	{
		if ('a' <= str[alpha - 1] && str[alpha - 1] <= 'z')
			alpha++;
		else
			alpha = 0;
	}
	if (alpha)
		alpha = 1;
	return (alpha);
}
