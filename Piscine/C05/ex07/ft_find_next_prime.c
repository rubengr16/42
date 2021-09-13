/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:34:32 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/21 00:57:51 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	result;

	if (nb < 0)
		result = 0;
	else
	{
		result = 2;
		while ((result <= (nb / 2)) && result)
		{
			if (!(nb % result))
				result = 0;
			else
				result++;
		}
		if (nb == 0 || nb == 1)
			result = 0;
		else if (result > (nb / 2))
			result = 1;
	}
	return (result);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 0)
		nb = 2;
	while (!(ft_is_prime(nb)) && (nb < 2147483647))
		nb++;
	return (nb);
}
