/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 19:30:34 by rgallego          #+#    #+#             */
/*   Updated: 2022/01/02 14:47:54 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
 * function which searchs for the correct full path of the command if possible
 * INPUT:	char **set_of_paths, char **path, char *cmd, int *cnt
 * OUTPUT:	void
 */
static void	try_path(char **set_of_paths, char **path, char *cmd, int *cnt)
{
	*cnt = 0;
	*path = ft_strjoinsep(set_of_paths[*cnt], cmd, "/");
	while (set_of_paths[*cnt] && access(*path, F_OK | X_OK))
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

/*void	forking(char ***set_of_cmds, int *pipefd)
{
	//int	fdout;
	int	pid;

	pid = fork();
	if (!pid)
	{
		close(pipefd[PIPE_RD]);
		if (dup2(pipefd[PIPE_WR], STDOUT_FILENO))
			error_msg(
	}
}*/