/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:09:57 by rgallego          #+#    #+#             */
/*   Updated: 2022/02/09 20:31:49 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

	i = 0;
	while (args.cmds[i])
	{
		j = 0;
		while (args.cmds[i][j])
		{
			free(args.cmds[i][j]);
			j++;
		}
		free(args.cmds[i]);
		i++;
	}
}

void	error_msg(t_args args, char *str, int error)
{
	if (error == ERR_ARGC)
	{
		ft_putendl_fd("Please, enter 4 arguments with the structure:", \
				STDOUT_FILENO);
		ft_putendl_fd("./pipex <file1> <cmd1> <cmd2> <file2>", STDOUT_FILENO);
	}
	else if (error == ERR_ENVP)
		ft_putendl_fd("Please, enable the environment variables", \
				STDOUT_FILENO);
	else if (error == ERR_CMD || error == ERR_PIPE)
		perror(str);
	free_set_of_cmd(args);
	exit(error);
}

/*
 * function which receives argv to divide the given commands into command 
 * and flag. Each command and its flag is stored in its position in the
 * cmds array
 * INPUT:	char **cmds[], char **argv
 * OUTPUT:	void
 */
void	separate_flag(char **cmds[], char **argv)
{
	int	i;
	int	cnt;

	i = 2;
	cnt = 0;
	while (cnt < 2)
	{
		cmds[cnt] = ft_split(argv[i], ' ');
		i++;
		cnt++;
	}
	cmds[cnt] = NULL;
}

char	*ft_strjoinsep(char const *s1, char const *s2, char *c)
{
	int		len;
	char	*s;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 2;
	s = malloc(sizeof(char) * (len));
	if (!s)
		return (NULL);
	(void)ft_strlcpy(s, s1, len);
	(void)ft_strlcat(s, c, len);
	(void)ft_strlcat(s, s2, len);
	return (s);
}
