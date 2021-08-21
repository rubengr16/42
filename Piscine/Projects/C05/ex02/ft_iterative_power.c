/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 08:58:08 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/21 02:42:58 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	pow;

	if (power >= 0)
	{
		pow = 1;
		while (power > 0)
		{
			pow *= nb;
			power--;
		}
	}
	else
		pow = 0;
	return (pow);
}
