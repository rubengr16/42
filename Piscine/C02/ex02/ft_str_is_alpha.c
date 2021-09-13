/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 11:41:10 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/12 11:08:18 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	alpha;

	alpha = 1;
	while (str[alpha - 1] && alpha)
	{
		if (('a' <= str[alpha - 1] && str[alpha - 1] <= 'z')
			|| ('A' <= str[alpha - 1] && str[alpha - 1] <= 'Z'))
			alpha++;
		else
			alpha = 0;
	}
	if (alpha)
		alpha = 1;
	return (alpha);
}
