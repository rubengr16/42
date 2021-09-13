/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 20:00:25 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/20 09:17:49 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	result;

	result = 0;
	if (nb >= 0)
	{
		result = 1;
		while (nb > 0)
		{
			result *= nb;
			nb--;
		}
	}
	return (result);
}
