/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:09:57 by rgallego          #+#    #+#             */
/*   Updated: 2022/01/01 22:24:50 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_msg(int error, char *str)
{
	if (error == ERR_CMD)
		perror(str);
	else if (error == ERR_NB_ARGC)
	{	
		ft_putendl_fd("Please, enter 4 arguments with the structure:", 1);
		ft_putendl_fd("./pipex file1 cmd1 cmd2 file2", 1);
	}
	exit(error);
}

void	free_set(char **set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		free(set[i]);
		i++;
	}
	free(set);
}

char	*ft_strjoinsep(char const *s1, char const *s2, char *c)
{
	int		len;
	char	*s;

	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2) + 2;
		s = malloc(sizeof(char) * (len));
		if (s)
		{
			(void)ft_strlcpy(s, s1, len);
			(void)ft_strlcat(s, c, len);
			(void)ft_strlcat(s, s2, len);
		}
		return (s);
	}
	else
		return (NULL);
}
