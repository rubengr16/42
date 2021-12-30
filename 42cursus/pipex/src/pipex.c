/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 19:30:34 by rgallego          #+#    #+#             */
/*   Updated: 2021/12/30 18:06:06 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int i = 0;
	char *str;

	(void)argc;
	while (argv[i])
		printf("\n%s", argv[i++]);
	printf("\n%s", argv[i]);
	i = 0;
	printf("%s\n\n", &envp[i][5]);
	if (!envp[i])
		printf("fuck u");
	while (envp[i])
	{
		printf("%s\n", envp[i]);
		i++;
	}
	str = isvalidcmd(argv[1], envp);
	if (str)
		printf("\nYay");
	else
		printf("\nNay");
//	system("leaks pipex");
	return (0);
}

static void	try_path(char **set_of_paths, char **path, char *cmd, int *cnt)
{
	*cnt = 0;
	*path = ft_strjoinsep(set_of_paths[*cnt], cmd, "/");
	while (set_of_paths[*cnt] && access(*path, X_OK))
	{
		free(*path);
		(*cnt)++;
		*path = ft_strjoinsep(set_of_paths[*cnt], cmd, "/");
	}
}

/*
 * function which receives a command -cmd- and the environment variables in
 * envp. It searchs for the "PATH=" variable, splits all the paths and later
 * adds them to the cmd in order to test if there is access to the required
 * commmand. 
 * INPUT:	char *cmd, char **envp
 * OUTPUT:	int	:	1	command is valid
 * 					0	invalid command
 */
char	*isvalidcmd(char *cmd, char **envp)
{
	int		cnt;
	char	*path;
	char	**set_of_paths;

	cnt = 0;
	while (envp[cnt]
		&& !ft_strnstr(envp[cnt], "PATH=", 5))
		cnt++;
	if (envp[cnt])
	{
		set_of_paths = ft_split(&envp[cnt][5], ':');
		if (set_of_paths)
		{
			try_path(set_of_paths, &path, cmd, &cnt);
			free_set(set_of_paths);
			if (!set_of_paths[cnt])
			{
				free(path);
				path = NULL;
			}
		}
	}
	return (path);
}
