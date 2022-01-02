/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 02:23:00 by rgallego          #+#    #+#             */
/*   Updated: 2022/01/02 02:24:52 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char	***set_of_cmds;
	int		pipefd[2];
//	int		fout;
	int		pid;

	set_of_cmds = NULL;
	separate_flag(&set_of_cmds, argv);
	if (argc != 5)
		error_msg(&set_of_cmds, "", ERR_ARGC);
	else if (!envp[0])
		error_msg(&set_of_cmds, "", ERR_ENVP);
	else if (!isvalidcmd(&(set_of_cmds[0][CMD]), envp))
		error_msg(&set_of_cmds, set_of_cmds[0][CMD], ERR_CMD);
	else if (!isvalidcmd(&(set_of_cmds[1][CMD]), envp))
		error_msg(&set_of_cmds, set_of_cmds[1][CMD], ERR_CMD);
	else if (pipe(pipefd))
		error_msg(&set_of_cmds, "", ERR_PIPE);
	pid = fork();
	if (!pid)
		execve(set_of_cmds[0][CMD], set_of_cmds[0], envp);
	execve(set_of_cmds[1][CMD], set_of_cmds[1], envp);
	wait(NULL);
	return (0);
}
