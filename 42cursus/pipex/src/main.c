/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 02:23:00 by rgallego          #+#    #+#             */
/*   Updated: 2022/09/21 20:14:23 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_args	args;
	int		pipefd[2];

	args = (t_args){0, 0, NULL, NULL};
	if (argc < 5)
		error_msg(args, NULL, ERR_ARGC);
	preparate_pipex(&args, argv);
	if (!envp[0])
		error_msg(args, NULL, ERR_ENVP);
	if (!arevalidcmds(args.cmds, envp))
		error_msg(args, NULL, ERR_CMD);
	if (pipe(pipefd))
		error_msg(args, "pipe error", ERR_PIPE);
	return (executor(args, envp, pipefd));
}
