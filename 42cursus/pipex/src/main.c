/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 02:23:00 by rgallego          #+#    #+#             */
/*   Updated: 2022/09/22 09:44:16 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	pipex.fdin = -1;
	pipex.fdout = -1;
	pipex.limiter = NULL;
	pipex.cmds = NULL;
	if (argc < 5)
		error_msg(pipex, NULL, ERR_ARGC);
	preparate_pipex(&pipex, argv);
	arevalidcmds(pipex, envp);
	if (pipe(pipex.pipefd))
		error_msg(pipex, "pipe failed", ERR_SYS);
	return (executor(pipex, envp));
}
