/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 02:23:00 by rgallego          #+#    #+#             */
/*   Updated: 2022/02/09 21:05:17 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	leak(void)
{
	system("leaks pipex");
}

int	main(int argc, char **argv, char **envp)
{
	t_args	args;
	int		pipefd[2];
	atexit(leak);

	(void)argv;
	args = (t_args){0, 0, {NULL}};
	if (argc != 5)
		error_msg(args, NULL, ERR_ARGC);
	if (!envp[0])
		error_msg(args, NULL, ERR_ENVP);
	separate_flag(args.cmds, argv);
	if (!isvalidcmd(&(args.cmds[0][CMD]), envp))
		error_msg(args, args.cmds[0][CMD], ERR_CMD);
	if (!isvalidcmd(&(args.cmds[1][CMD]), envp))
		error_msg(args, args.cmds[1][CMD], ERR_CMD);
	args.fd_in = open(argv[1], O_RDONLY);
	if (args.fd_in < 0)
		error_msg(args, argv[1], ERR_OPEN);
	args.fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC);
	if (args.fd_out < 0)
		error_msg(args, argv[4], ERR_OPEN);
	if (pipe(pipefd))
		error_msg(args, "pipe error", ERR_PIPE);
	//forking(args, pipefd);
//	wait(NULL);
	return (0);
}
