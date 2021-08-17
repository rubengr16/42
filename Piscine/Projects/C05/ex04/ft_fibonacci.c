/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 09:13:06 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/17 09:20:53 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci_aux(int index)
{
	if (index == 0 || index == 1)
		return (index);
	else
		return (ft_fibonacci_aux(index - 1) + ft_fibonacci_aux(index - 2));
}

int	ft_fibonacci(int index)
{
	if (index >= 0)
		return (ft_fibonacci_aux(index));
	else
		return (-1);
}
