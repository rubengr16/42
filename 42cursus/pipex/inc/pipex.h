/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 19:24:05 by rgallego          #+#    #+#             */
/*   Updated: 2022/01/02 02:25:12 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/*************************** COMMAND STRUCTURE ***************************** */
# define CMD 0
# define FLAG 1

/**************************** ERROR MANAGEMENT ***************************** */
# define ERR_ARGC 1
# define ERR_ENVP 2
# define ERR_CMD 3
# define ERR_PIPE 4

/***************************** PIPE MANAGEMENT ***************************** */
# define PIPE_RD 0
# define PIPE_WR 1

# include <sys/wait.h> /*** pid_t	wait(int *wsatus); ***/
# include <stdio.h> /*** void	perror(const char *s); ***/
//# include <errno.h> /*** error	constants ***/
# include <unistd.h> /*** int	dup2(int oldfd, int newfd);
						  pid_t	fork(void);
						  int pipe(int pipefd[2]); ***/
# include <stdlib.h>
# include "libft.h"

/********************************* UTILS *********************************** */
void	free_set(char **set);
void	free_set_of_cmd(char ****set_of_cmds);
void	error_msg(char ****set_of_cmds, char *str, int error);
char	*ft_strjoinsep(char const *s1, char const *s2, char *c);

/********************************* PIPEX *********************************** */
void	separate_flag(char ****set_of_cmds, char **argv);
char	*isvalidcmd(char **cmd, char **envp);

#endif
