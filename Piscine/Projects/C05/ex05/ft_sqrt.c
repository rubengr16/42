/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 12:05:33 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/21 00:50:02 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	sqrt_nb;
	int	pow_sqrt;

	sqrt_nb = 0;
	if (nb > 0)
	{
		while ((sqrt_nb * sqrt_nb) < nb && sqrt_nb < 46341)
		{
			sqrt_nb++;
			pow_sqrt = sqrt_nb * sqrt_nb;
		}
		if ((sqrt_nb * sqrt_nb) > nb || sqrt_nb >= 46341)
			sqrt_nb = 0;
	}
	return (sqrt_nb);
}
