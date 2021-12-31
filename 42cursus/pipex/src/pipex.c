/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 19:30:34 by rgallego          #+#    #+#             */
/*   Updated: 2021/12/31 19:04:25 by rgallego         ###   ########.fr       */
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

void	error_msg(int error, char *str)
{
	if (error == ERR_CMD)
	{
		perror("COMMAND NOT FOUND");
		ft_putstr_fd(str, 1);
		ft_putendl_fd(": command not found", 1);
		ft_putendl_fd(strerror(ENOENT), 1);
	}
	else if (error == ERR_NB_ARGC)
	{	
		ft_putendl_fd("Please, enter 4 arguments with the structure:", 1);
		ft_putendl_fd("./pipex file1 cmd1 cmd2 file2", 1);
	}
}

int	main(int argc, char **argv, char **envp)
{
	char	***set_of_cmds;
	int		i = 0;
	int		j = 0;

	(void)envp;
	if (argc == 5)
	{
		set_of_cmds = NULL;
		separate_flag(&set_of_cmds, argv);
		if (isvalidcmd(&(set_of_cmds[0][CMD]), envp))
		{
			if (isvalidcmd(&(set_of_cmds[1][CMD]), envp))
			{
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
				execve(set_of_cmds[0][CMD], set_of_cmds[0], envp);
			}
			else
				error_msg(ERR_CMD, set_of_cmds[1][CMD]);
		}
		else
			error_msg(ERR_CMD, set_of_cmds[0][CMD]);
	}
	else
		error_msg(ERR_NB_ARGC, "");
/*	
 *	int i = 0;
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
char	*isvalidcmd(char **cmd, char **envp)
{
	int		cnt;
	char	*path;
	char	**set_of_paths;

	cnt = 0;
	path = NULL;
	while (envp[cnt] && !ft_strnstr(envp[cnt], "PATH=", 5))
		cnt++;
	if (envp[cnt])
	{
		set_of_paths = ft_split(&envp[cnt][5], ':');
		if (set_of_paths)
		{
			try_path(set_of_paths, &path, *cmd, &cnt);
			free_set(set_of_paths);
			if (!set_of_paths[cnt])
			{
				free(path);
				path = NULL;
			}
			else
				*cmd = path;
		}
	}
	return (path);
}
