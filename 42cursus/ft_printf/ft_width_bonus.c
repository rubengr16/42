/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 12:17:10 by rgallego          #+#    #+#             */
/*   Updated: 2021/11/14 17:39:12 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_width(char *str, int *cnt)
{
	int	n_space;

	n_space = 0;
	while ('0' <= str[*cnt] && str[*cnt] <= '9')
	{
		n_space = (n_space * 10) + (str[*cnt] - '0');
		(*cnt)++;
	}
	return (n_space);
}
