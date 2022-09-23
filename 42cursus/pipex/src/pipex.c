/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 19:30:34 by rgallego          #+#    #+#             */
/*   Updated: 2022/09/23 15:06:48 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
 * won't read from fdout and establishes the correct fds for the PIPE_WR and
 * fdin. Later, itexecutes the first command.
 * INPUT:	t_pipex, char **envp
 * OUTPUT:	void
 */
static void	first_child(t_pipex pipex, char **envp)
{
	int	n_pipe;

	n_pipe = pipex.cmds->n_elem % 2;
	close(pipex.pipefd[n_pipe][PIPE_RD]);
	close(pipex.fdout);
	if (dup2(pipex.fdin, STDIN_FILENO) == ERR_DUP2)
		error_msg(pipex, "dup2 failed", ERR_SYS);
	if (dup2(pipex.pipefd[n_pipe][PIPE_WR], STDOUT_FILENO) == ERR_DUP2)
		error_msg(pipex, "dup2 failed", ERR_SYS);
	close(pipex.pipefd[n_pipe][PIPE_WR]);
	execve(pipex.cmds->head->cmd_flag[CMD], pipex.cmds->head->cmd_flag, envp);
}

/*
 * won't use fdout and establishes the chosen fds for both sides of the pipe.
 * Later, it executes the middle commands.
 * INPUT:	t_pipex, char **envp
 * OUTPUT:	void
 */
static void	middle_child(t_pipex pipex, char **envp)
{
	int	n_pipe;
	int	n_prevpipe;

	n_pipe = pipex.cmds->n_elem % 2;
	n_prevpipe = (pipex.cmds->n_elem + 1) % 2;
	close(pipex.fdout);
	if (dup2(pipex.pipefd[n_prevpipe][PIPE_RD], STDIN_FILENO) == ERR_DUP2)
		error_msg(pipex, "dup2 failed", ERR_SYS);
	close(pipex.pipefd[n_prevpipe][PIPE_RD]);
	if (dup2(pipex.pipefd[n_pipe][PIPE_WR], STDOUT_FILENO) == ERR_DUP2)
		error_msg(pipex, "dup2 failed", ERR_SYS);
	close(pipex.pipefd[n_pipe][PIPE_WR]);
	execve(pipex.cmds->head->cmd_flag[CMD], pipex.cmds->head->cmd_flag, envp);
}

/*
 * executes the last command after getting the chosen fds for fdout and PIPE_RD
 * INPUT:	t_pipex, char **envp
 * OUTPUT:	void
 */
static void	last_child(t_pipex pipex, char **envp)
{
	int	n_prevpipe;

	n_prevpipe = (pipex.cmds->n_elem + 1) % 2;
	if (dup2(pipex.fdout, STDOUT_FILENO) == ERR_DUP2)
		error_msg(pipex, "dup2 failed", ERR_SYS);
	if (dup2(pipex.pipefd[n_prevpipe][PIPE_RD], STDIN_FILENO) == ERR_DUP2)
		error_msg(pipex, "dup2 failed", ERR_SYS);
	close(pipex.pipefd[n_prevpipe][PIPE_RD]);
	execve(pipex.cmds->head->cmd_flag[CMD], pipex.cmds->head->cmd_flag, envp);
}

/*
 * executes all the forks and waits for them to terminate. Manages the
 * memory liberation of cmds and limiter, as well as, the closing of
 * files.
 * INPUT:	t_pipex, char **envp
 * OUTPUT:	int
 */
void	executor(t_pipex pipex, char **envp)
{
	if (pipe(pipex.pipefd[pipex.cmds->n_elem % 2]))
		error_msg(pipex, "pipe failed", ERR_SYS);
	if (!fork())
		first_child(pipex, envp);
	cmdslistdelone(pipex.cmds);
	close(pipex.fdin);
	if (pipex.limiter)
		unlink(PATH_DOC);
	while (pipex.cmds->n_elem > 1)
	{
		if (pipe(pipex.pipefd[pipex.cmds->n_elem % 2]))
			error_msg(pipex, "pipe failed", ERR_SYS);
		if (!fork())
			middle_child(pipex, envp);
		cmdslistdelone(pipex.cmds);
	}
	close(pipex.pipefd[(pipex.cmds->n_elem + 1) % 2][PIPE_WR]);
	if (!fork())
		last_child(pipex, envp);
	close(pipex.pipefd[(pipex.cmds->n_elem + 1) % 2][PIPE_RD]);
	close(pipex.fdout);
	cmdslistdelone(pipex.cmds);
	while (pipex.cmds->n_elem)
		wait(NULL);
	cmdslistdelall(pipex.cmds);
}
