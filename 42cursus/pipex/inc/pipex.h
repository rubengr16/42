/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 19:24:05 by rgallego          #+#    #+#             */
/*   Updated: 2021/12/31 18:44:44 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define CMD 0
# define FLAG 1

# define ERR_CMD 1
# define ERR_NB_ARGC 2

# include <unistd.h>
# include <stdlib.h>
# include "libft.h" 

/********************************* UTILS *********************************** */
void	free_set(char **set);
char	*ft_strjoinsep(char const *s1, char const *s2, char *c);
void	error_msg(int	error, char *str);

/********************************* PIPEX *********************************** */
char	*isvalidcmd(char **cmd, char **envp);

#endif
