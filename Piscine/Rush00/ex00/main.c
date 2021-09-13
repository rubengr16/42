/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalabuc <mcalabuc@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 11:27:46 by mcalabuc          #+#    #+#             */
/*   Updated: 2021/08/08 18:40:33 by mtacunan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	rush(int x, int y);

int	atoi(char *nbr_str)
{
	int	num;

	num = 0;
	if (*nbr_str != '-')
	{
		while ('0' <= *nbr_str && *nbr_str <= '9')
		{
			num = num * 10 + (*nbr_str - '0');
			nbr_str++;
		}
	}
	else
		num = -1;
	if (*nbr_str != '\0' && *nbr_str != '-')
		num = -2;
	return (num);
}

void	print_str(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}

void	display_error(int error)
{
	if (error / 4)
	{
		print_str("Warning. Please, enter 2 arguments\n");
		error %= 4;
	}
	if (error / 2)
	{
		print_str("Warning. Please, enter only numbers.\n");
		error %= 2;
	}
	if (error / 1)
	{
		print_str("Warning. Please, enter a number greater than 0.\n");
	}
}

int	main(int argc, char **argv)
{
	int	x;
	int	y;
	int	error;

	error = 0;
	if (argc == 3)
	{
		x = atoi(argv[1]);
		y = atoi(argv[2]);
		if (x == -1 || y == -1 || x == 0 || y == 0)
			error += 1;
		if (x == -2 || y == -2)
			error += 2;
		else
			if (error == 0)
				rush(x, y);
	}
	else
		error += 4;
	if (error != 0)
		display_error(error);
	return (error);
}
