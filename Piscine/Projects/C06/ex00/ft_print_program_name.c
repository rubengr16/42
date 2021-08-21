/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 19:08:32 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/20 10:42:07 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	cnt;

	cnt = -1;
	while (str[++cnt])
		write(1, &str[cnt], 1);
}

int	main(int argc, char **argv)
{
	if (argc)
	{
		ft_putstr(argv[0]);
		ft_putstr("\n");
	}
	return (0);
}
