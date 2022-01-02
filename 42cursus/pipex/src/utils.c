/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:09:57 by rgallego          #+#    #+#             */
/*   Updated: 2022/01/02 15:38:06 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

void	free_set(char **set)
{
	int	i;

	if (set)
	{
		i = 0;
		while (set[i])
		{
			free(set[i]);
			i++;
		}
		free(set);
	}
}

void	free_set_of_cmd(t_args args)
{
	int	i;
	int	j;

	if (args)
	{
		j = 0;
		while ((args.set_of_cmds)[j])
		{
			i = 0;
			printf("i = %i, j = %i", i, j);
			while ((args.set_of_cmds)[j][i])
			{
				free((args.set_of_cmds)[j][i]);
				i++;
				printf("i = %i, j = %i", i, j);
			}
			free(set_of_cmds[j]);
			j++;
			printf("i = %i, j = %i", i, j);
		}
	}
}

void	error_msg(t_args args, char *str, int error)
{
	if (error == ERR_ARGC)
	{
		ft_putendl_fd("Please, enter 4 arguments with the structure:", 1);
		ft_putendl_fd("./pipex <file1> <cmd1> <cmd2> <file2>", 1);
	}
	else if (error == ERR_ENVP)
		ft_putendl_fd("Please, enable the environment variables", 1);
	else if (error == ERR_MALLOC || error == ERR_CMD || error == ERR_PIPE)
		perror(str);
	free_set_of_cmd(args);
	exit(error);
}

void	separate_flag(t_args *args, char **argv, int argc)
{
	int	i;
	int	cnt;

	if (argc == 6)
		i = 3;
	else
		i = 2;
	cnt = 0;
	args->n_cmds = argc - i;
	args->set_of_cmds = malloc(sizeof(char **) * (args->n_cmds));
	if (args->set_of_cmds)
	{
		while(cnt < args->n_cmds)
		{
			args->set_of_cmds[cnt] = ft_split(argv[i], ' ');
			i++;
			cnt++;
		}
	}
}


char	*ft_strjoinsep(char const *s1, char const *s2, char *c)
{
	int		len;
	char	*s;

	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2) + 2;
		s = malloc(sizeof(char) * (len));
		if (s)
		{
			(void)ft_strlcpy(s, s1, len);
			(void)ft_strlcat(s, c, len);
			(void)ft_strlcat(s, s2, len);
		}
		return (s);
	}
	else
		return (NULL);
}
