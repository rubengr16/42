/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 12:28:29 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/15 18:43:01 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	backtracking_call(int sol[4][4], char inp[16]);

void	is_val_argv(char	*argv, char inp[16])
{
	int	i;
	int	j;
	int	out;

	i = 0;
	j = 0;
	out = 0;
	while (j < 16 && i < 32 && !out)
	{
		if (i % 2 == 0)
		{
			if (argv[i] < '1' || '4' < argv[i])
				out = 1;
			else
			{
				inp[j] = argv[i];
				j++;
			}
		}
		else if (argv[i] != ' ' && argv[i] != '\0')
			out = 1;
		i++;
	}
	if (out || j != 16 || argv[i])
		inp[0] = '\0';
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	write_sol(int sol[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_putchar(sol[i][j] + '0');
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	ft_init(int sol[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			sol[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		sol[4][4];
	char	inp[16];

	is_val_argv(argv[1], inp);
	if (argc == 2 && inp[0])
	{
		ft_init(sol);
		if (backtracking_call(sol, inp))
		{
			write_sol(sol);
		}
		else
			write(1, "Error\n", 6);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
