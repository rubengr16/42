/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugonzal <jugonzal@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 12:22:31 by jugonzal          #+#    #+#             */
/*   Updated: 2021/08/22 14:44:13 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "struct.h"

char	*ft_quit_space(char *str)
{
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t'
			|| *str == '\v' || *str == '\f' || *str == '\r'))
		str++;
	return (str);
}

int	main(int argc, char **argv)
{
	char	*file;
	t_list	*list;

	if (1 < argc && argc < 4)
	{
		argv[1] = ft_quit_space(argv[1]);
		if (*(argv[1]) != '-')
		{
			if (argc == 2)
				file = ft_read_file("numbers.dict");
			else
				file = ft_read_file(argv[2]);
			if (file)
			{
				list = NULL;
				ft_init(list);
				set_info(list, file);
				ft_write_num(list, argv[1]);
			}	
		}
		if (*(argv[1]) == '-' || !file)
			write(1, "Error\n", 6);
	}
	else
		write(1, "Error\n", 6);
}
