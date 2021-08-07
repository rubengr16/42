/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 08:57:50 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/06 09:29:54 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	car[5];

	car[3] = ',';
	car[4] = ' ';
	car[0] = '0';
	while ('0' <= car[0] && car[0] <= '9')
	{
		car[1] = '0';
		while ('0' <= car[1] && car[1] <= '9')
		{
			car[2] = '0';
			while ('0' <= car[2] && car[2] <= '9')
			{
				if (car[0] == '9' && car[1] == '8' && car[2] == '7')
					write(1, &car, 3);
				else
					if (car[0] != car[1] && car[1] != car[2]
						&& car[2] != car[0])
						write(1, &car, 5);
				car[2]++;
			}
			car[1]++;
		}
		car[0]++;
	}
}	

int	main(void)
{
	ft_print_comb();
}
