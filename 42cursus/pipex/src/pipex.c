/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 19:30:34 by rgallego          #+#    #+#             */
/*   Updated: 2021/12/27 19:54:47 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int i = 0;

	(void)argc;
	(void)argv;
	printf("%s\n\n", &envp[i][5]);
	if (!envp[i])
		printf("fuck u");
	while (envp[i])
	{
		printf("%s\n", envp[i]);
		i++;
	}
	if (isvalidcmd(argv[1], envp))
		printf("\nYay");
	else
		printf("\nNay");
	return (0);
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
int	isvalidcmd(char *cmd, char **envp)
{
	int		cnt;
	char	*path;
	char	**set_of_paths;

	cnt = 0;
	while (envp[cnt]
		&& !ft_strnstr(envp[cnt], "PATH=", ft_strlen(envp[cnt]) - 5))
		cnt++;
	if (envp[cnt])
	{
		set_of_paths = ft_split(&envp[cnt][5], ':');
		if (set_of_paths)
		{
			cnt = 0;
			path = ft_strjoin(ft_strjoin(set_of_paths[cnt], "/"), cmd);
			while (set_of_paths[cnt] && access(path, X_OK))
			{
				cnt++;
				path = ft_strjoin(ft_strjoin(set_of_paths[cnt], "/"), cmd);
			}
			if (set_of_paths[cnt])
				return (1);
		}
	}
	return (0);
}
