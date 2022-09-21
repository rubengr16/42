/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 19:24:05 by rgallego          #+#    #+#             */
/*   Updated: 2022/09/21 22:01:06 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/******************************** LIBRARIES ********************************* */
# include <sys/wait.h>		/***	pid_t	wait(int *wsatus);	***/
# include <stdio.h>		/***	void	perror(const char *s);	***/
# include <errno.h>
# include <unistd.h>	/***	int		dup2(int oldfd, int newfd);
						  		pid_t	fork(void);
						  		int 	pipe(int pipefd[2]);	***/
# include <stdlib.h>
# include <fcntl.h>		/***	int		open(const char *path, int oflag, ...);
								***/
# include "libft.h"
# include "get_next_line.h"
# include "cmdslist.h"

/**************************** ERROR MANAGEMENT ****************************** */
# define ERR_ARGC 1
# define ERR_ENVP 2
# define ERR_CMD 3
# define ERR_PIPE 4
# define ERR_OPEN 5
# define ERR_SPLIT 6

/***************************** PIPE MANAGEMENT ****************************** */
# define PIPE_RD 0
# define PIPE_WR 1

/******************************** HERE_DOC ********************************** */
# define HERE_DOC "here_doc"
# define PATH_DOC "/tmp/here_doc"

/******************************* STRUCTURE ********************************** */
typedef struct s_args
{
	int			fdin;
	int			fdout;
	char		*limiter;
	t_cmdslist	*cmds;
}	t_args;

/********************************* UTILS ************************************ */
void	error_msg(t_args args, char *str, int error);
void	preparate_pipex(t_args *args, char **argv);
char	*ft_strjoinsep(char const *s1, char const *s2, char *c);

/********************************* PIPEX ************************************ */
char	*arevalidcmds(t_cmdslist *cmds, char **envp);
int		executor(t_args args, char **envp, int *pipefd);
void	first_child(t_args args, char **envp, int *pipefd);
void	middle_child(t_args args, char **envp, int *pipefd);
void	last_child(t_args args, char **envp, int *pipefd);

#endif
