/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 11:27:37 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/10 11:47:22 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	numeric;

	numeric = 1;
	if (*str == '-')
		numeric++;
	while (numeric && str[numeric - 1] != '\0')
	{
		if ('0' <= str[numeric - 1] && str[numeric - 1] <= '9')
			numeric++;
		else
			numeric = 0;
	}
	if (numeric)
		numeric = 1;
	return (numeric);
}
