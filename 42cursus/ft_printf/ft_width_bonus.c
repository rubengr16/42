/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 12:17:10 by rgallego          #+#    #+#             */
/*   Updated: 2021/11/01 12:18:39 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_width_bonus(char *str, int *cnt)
{
	int	n_space;

	n_space = 0;
	while ('0' <= str[*cnt] && str[*cnt] <= '9')
	{
		(*cnt)++;
		n_space++;
	}
	return (n_space);
}
