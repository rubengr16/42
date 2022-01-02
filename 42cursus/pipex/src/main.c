/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 02:23:00 by rgallego          #+#    #+#             */
/*   Updated: 2022/01/02 15:36:34 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_args	args;
	int		pipefd[2];

	if (argc != 5)
		error_msg(NULL, NULL, ERR_ARGC);
	else if (!envp[0])
		error_msg(NULL, NULL, ERR_ENVP);
	separate_flag(&args, argv, argc);
	if (!isvalidcmd(&(args.set_of_cmds[0][CMD]), envp))
		error_msg(args, args.set_of_cmds[0][CMD], ERR_CMD);
	else if (!isvalidcmd(&(args.set_of_cmds[1][CMD]), envp))
		error_msg(args, args.set_of_cmds[1][CMD], ERR_CMD);
	else if (pipe(pipefd))
		error_msg(args, "pipe error: ", ERR_PIPE);
//	forking(set_of_cmds, pipefd);
//	wait(NULL);
	return (0);
}
