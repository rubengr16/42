/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 19:30:34 by rgallego          #+#    #+#             */
/*   Updated: 2022/01/01 23:09:15 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	separate_flag(char ****set_of_cmds, char **argv)
{
	*set_of_cmds = malloc(sizeof(char **) * 3);
	(*set_of_cmds)[0] = ft_split(argv[2], ' ');
	(*set_of_cmds)[1] = ft_split(argv[3], ' ');
	(*set_of_cmds)[2] = NULL;
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

int	main(int argc, char **argv, char **envp)
{
	char	***set_of_cmds;
	int		pipefd[2];
	int		fout;
	int		pid;

	(void)envp;
	if (argc == 5)
	{
		set_of_cmds = NULL;
		separate_flag(&set_of_cmds, argv);
		if (isvalidcmd(&(set_of_cmds[0][CMD]), envp))
		{
			if (isvalidcmd(&(set_of_cmds[1][CMD]), envp))
			{
				if (!pipe(pipefd))
				{
					pid = fork();
					if (!pid)
						execve(set_of_cmds[0][CMD], set_of_cmds[0], envp);
					execve(set_of_cmds[1][CMD], set_of_cmds[1], envp);
					wait(NULL);
				}

			}
			else
				error_msg(ERR_CMD, set_of_cmds[1][CMD]);
		}
		else
			error_msg(ERR_CMD, set_of_cmds[0][CMD]);
	}
	else
		error_msg(ERR_NB_ARGC, "");
	return (0);
}
