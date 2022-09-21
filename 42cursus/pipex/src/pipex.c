/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 19:30:34 by rgallego          #+#    #+#             */
/*   Updated: 2022/09/21 22:12:10 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
