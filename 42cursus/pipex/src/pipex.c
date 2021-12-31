/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 19:30:34 by rgallego          #+#    #+#             */
/*   Updated: 2021/12/31 12:05:21 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "pipex.h"

void	separate_flag(char ****set_of_cmds, char **argv)
{
	*set_of_cmds = malloc(sizeof(char **) * 3);
	(*set_of_cmds)[0] = ft_split(argv[2], ' ');
	(*set_of_cmds)[1] = ft_split(argv[3], ' ');
	(*set_of_cmds)[2] = NULL;
}

void	error_msg(int error)
{
	if (error == BAD_NB_ARGC)
		ft_putendl_fd("Enter 4 arguments with the following structure:", 1);
	ft_putendl_fd("./pipex file1 cmd1 cmd2 file2", 1);
}

int	main(int argc, char **argv, char **envp)
{
	char	***set_of_cmds;
	char	*path;
	int		i = 0;
	int		j = 0;

	(void)envp;
	if (argc != 5)
		error_msg(BAD_NB_ARGC);
	set_of_cmds = NULL;
	separate_flag(&set_of_cmds, argv);
	while (set_of_cmds[i])
	{
		j = 0;
		while (set_of_cmds[i][j])
		{
			printf("\n%s", set_of_cmds[i][j]);
			j++;
		}
		i++;
	}
	//perror("Fuck u");
	path = isvalidcmd(set_of_cmds[0][0], envp);
	execve(path, set_of_cmds[0], envp);
/*	int i = 0;
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
	system("leaks pipex"); */
	return (0);
}

/*
 * function which searchs for the correct full path of the command if possible
 * INPUT:	char **set_of_paths, char **path, char *cmd, int *cnt
 * OUTPUT:	void
 */
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
