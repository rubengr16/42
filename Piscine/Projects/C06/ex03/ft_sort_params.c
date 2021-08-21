/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 08:55:31 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/20 10:49:21 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	cont;

	cont = 0;
	while (s1[cont] == s2[cont] && s1[cont] && s2[cont])
		cont++;
	return (s1[cont] - s2[cont]);
}

void	ft_sort_argv(int argc, char **argv)
{
	int		i;
	int		j;
	char	*aux;

	j = 0;
	while (j < (argc - 1))
	{
		i = 2;
		while (i < (argc - j))
		{
			if (ft_strcmp(argv[i - 1], argv[i]) > 0)
			{
				aux = argv[i];
				argv[i] = argv[i - 1];
				argv[i - 1] = aux;
			}
			i++;
		}
		j++;
	}
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	ft_sort_argv(argc, argv);
	while (i < argc)
	{
		ft_putstr(argv[i]);
		ft_putstr("\n");
		i++;
	}
	return (0);
}
