/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 19:24:05 by rgallego          #+#    #+#             */
/*   Updated: 2022/01/21 11:45:03 by rgallego         ###   ########.fr       */
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
# define ERR_MALLOC 3
# define ERR_CMD 4
# define ERR_PIPE 5

/***************************** PIPE MANAGEMENT ***************************** */
# define PIPE_RD 0
# define PIPE_WR 1

# include <sys/wait.h>	/***	pid_t	wait(int *wsatus);	***/
# include <stdio.h>		/***	void	perror(const char *s);	***/
//# include <errno.h> /*** error	constants ***/
# include <unistd.h>	/***	int	dup2(int oldfd, int newfd);
						  		pid_t	fork(void);
						  		int pipe(int pipefd[2]);	***/
# include <stdlib.h>
# include "libft.h"

/*****************************  *********************************** */
typedef struct s_args
{
	int		fd_in;
	int		fd_out;
	int		n_cmds;
	char	***cmds;
}	t_args;

/********************************* UTILS *********************************** */
void	free_set(char **set);
void	free_set_of_cmd(t_args args);
void	error_msg(t_args args, char *str, int error);
void	separate_flag(t_args *args, char **argv);
char	*ft_strjoinsep(char const *s1, char const *s2, char *c);

/********************************* PIPEX *********************************** */
char	*isvalidcmd(char **cmd, char **envp);
//void	forking(char ***set_of_cmds, int *pipefd);

#endif
