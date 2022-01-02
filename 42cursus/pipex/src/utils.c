/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:09:57 by rgallego          #+#    #+#             */
/*   Updated: 2022/01/02 02:21:29 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_set(char **set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		free(set[i]);
		i++;
	}
	free(set);
}

void	free_set_of_cmd(char ****set_of_cmds)
{
	int	i;
	int	j;

	j = 0;
	while ((*set_of_cmds)[j])
	{
		i = 0;
		while ((*set_of_cmds)[j][i])
		{
			free((*set_of_cmds)[j][i]);
			i++;
		}
		free((*set_of_cmds)[j]);
		j++;
	}
}

void	error_msg(char ****set_of_cmds, char *str, int error)
{
	if (error == ERR_ARGC)
	{
		ft_putendl_fd("Please, enter 4 arguments with the structure:", 1);
		ft_putendl_fd("./pipex <file1> <cmd1> <cmd2> <file2>", 1);
	}
	else if (error == ERR_ENVP)
		ft_putendl_fd("Please, enable the environment variables", 1);
	else if (error == ERR_CMD || error == ERR_PIPE)
		perror(str);
	free_set_of_cmd(set_of_cmds);
	exit(error);
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
