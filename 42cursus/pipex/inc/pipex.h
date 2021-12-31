/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 19:24:05 by rgallego          #+#    #+#             */
/*   Updated: 2021/12/31 19:05:23 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/*************************** COMMAND STRUCTURE ***************************** */
# define CMD 0
# define FLAG 1

/*************************** ERRROR MANAGEMENT ***************************** */
# define ERR_CMD 1
# define ERR_NB_ARGC 2

# include <errno.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "libft.h"

/********************************* UTILS *********************************** */
void	free_set(char **set);
char	*ft_strjoinsep(char const *s1, char const *s2, char *c);
void	error_msg(int error, char *str);

/********************************* PIPEX *********************************** */
char	*isvalidcmd(char **cmd, char **envp);

#endif
