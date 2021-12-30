/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 19:24:05 by rgallego          #+#    #+#             */
/*   Updated: 2021/12/30 22:32:03 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define FLAG 1

# include <unistd.h>
# include <stdlib.h>
# include "libft.h" 

/********************************* UTILS *********************************** */
void	free_set(char **set);
char	*ft_strjoinsep(char const *s1, char const *s2, char *c);

/********************************* PIPEX *********************************** */
char	*isvalidcmd(char *cmd, char **envp);

#endif
