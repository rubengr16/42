/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 19:30:34 by rgallego          #+#    #+#             */
/*   Updated: 2022/09/21 22:01:26 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
 * function which searchs for the correct full path of the command if possible
 * INPUT:	char **set_of_paths, char **path, char *cmd, int *cnt
 * OUTPUT:	void
 */
static char	*try_path(char **set_of_paths, char *cmd)
{
	char	*path;
	int		cnt;

	cnt = 0;
	path = ft_strjoinsep(set_of_paths[cnt], cmd, "/");
	while (set_of_paths[cnt] && path && access(path, F_OK | X_OK))
	{
		free(path);
		cnt++;
		path = ft_strjoinsep(set_of_paths[cnt], cmd, "/");
	}
	if (!set_of_paths[cnt] || !path)
	{
		free(path);
		return (NULL);
	}
	free(cmd);
	return (path);
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
char	*arevalidcmds(t_cmdslist *cmds, char **envp)
{
	t_node	*aux;
	char	**set_of_paths;
	int		cnt;

	cnt = 0;
	while (envp[cnt] && !ft_strnstr(envp[cnt], "PATH=", 5))
		cnt++;
	if (!envp[cnt])
		return (NULL);
	set_of_paths = ft_split(&envp[cnt][5], ':');
	if (!set_of_paths)
		return (NULL);
	cnt = cmds->n_elem;
	while (cnt)
	{
		aux = cmdslistpop(cmds);
		aux->cmd_flag[CMD] = try_path(set_of_paths, aux->cmd_flag[CMD]);
		if (!aux->cmd_flag[CMD])
			return (NULL);
		cmdslistpush(cmds, aux);
		cnt--;
	}
	ft_free_split(set_of_paths);
	return (aux->cmd_flag[CMD]);
}

int	executor(t_args args, char **envp, int *pipefd)
{
	if (!fork())
		first_child(args, envp, pipefd);
	free(cmdslistpop(args.cmds));
	close(args.fdin);
	while (args.cmds->n_elem > 1)
	{
		if (!fork())
			middle_child(args, envp, pipefd);
		free(cmdslistpop(args.cmds));
	}
	close(pipefd[PIPE_WR]);
	if (args.limiter)
		unlink(PATH_DOC);
	if (!fork())
		last_child(args, envp, pipefd);
	free(cmdslistpop(args.cmds));
	close(pipefd[PIPE_RD]);
	close(args.fdout);
	while (args.cmds->n_elem)
		wait(NULL);
	cmdslistdelall(args.cmds);
	return (0);
}

void	first_child(t_args args, char **envp, int *pipefd)
{
	close(pipefd[PIPE_RD]);
	close(args.fdout);
	dup2(args.fdin, STDIN_FILENO);
	dup2(pipefd[PIPE_WR], STDOUT_FILENO);
	close(pipefd[PIPE_WR]);
	execve(args.cmds->head->cmd_flag[CMD], args.cmds->head->cmd_flag, envp);
}

void	middle_child(t_args args, char **envp, int *pipefd)
{
	close(args.fdout);
	dup2(pipefd[PIPE_RD], STDIN_FILENO);
	close(pipefd[PIPE_RD]);
	dup2(pipefd[PIPE_WR], STDOUT_FILENO);
	close(pipefd[PIPE_WR]);
	execve(args.cmds->head->cmd_flag[CMD], args.cmds->head->cmd_flag, envp);
}

void	last_child(t_args args, char **envp, int *pipefd)
{
	dup2(args.fdout, STDOUT_FILENO);
	dup2(pipefd[PIPE_RD], STDIN_FILENO);
	close(pipefd[PIPE_RD]);
	execve(args.cmds->head->cmd_flag[CMD], args.cmds->head->cmd_flag, envp);
}
