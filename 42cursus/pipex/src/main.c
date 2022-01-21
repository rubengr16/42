/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 02:23:00 by rgallego          #+#    #+#             */
/*   Updated: 2022/01/21 14:04:34 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

void	leak(void)
{
	system("leaks pipex");
}

int	main(int argc, char **argv, char **envp)
{
	atexit(leak);
	t_args	args;
//	int		pipefd[2];

	separate_flag(&args, argv);
	if (argc != 5)
		error_msg(args, NULL, ERR_ARGC);
	else if (!envp[0])
		error_msg(args, NULL, ERR_ENVP);
	else if (!isvalidcmd(&(args.cmds[0][CMD]), envp))
		error_msg(args, args.cmds[0][CMD], ERR_CMD);
	else if (!isvalidcmd(&(args.cmds[1][CMD]), envp))
		error_msg(args, args.cmds[1][CMD], ERR_CMD);
	free_set_of_cmd(args);
/*	else if (pipe(pipefd))
		error_msg(args, "pipe error: ", ERR_PIPE);
*/
//	forking(set_of_cmds, pipefd);
//	wait(NULL);
	return (0);
}
