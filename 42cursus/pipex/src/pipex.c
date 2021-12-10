/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 19:30:34 by rgallego          #+#    #+#             */
/*   Updated: 2021/12/10 20:26:10 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(int argc, char **argv, char **envp)
{
	int i = 0;

	printf("%s\n\n", &envp[i][5]);
	if (!envp[i])
		printf("fuck u");
	while (envp[i])
	{
		printf("%s\n", envp[i]);
		i++;
	}
}

int	ft_isvalidcmd(char *cmd, char **envp)
{
	int		cnt;
	char	*path;
	char	**set_of_paths;

	cnt = 0;
	while (envp[cnt]
		&& !ft_strnstr(envp[cnt], "PATH=", ft_strlen(envp[cnt]) - 5))
		cnt++;
	if (envp[cnt])
	{
		set_of_paths = ft_split(&envp[cnt][5], ':');
		if (set_of_paths)
		{
			cnt = 0;
			while (set_of_paths[cnt])
			{
				*path = ft_strjoin(ft_strjoin(set_of_paths[cnt], "/"), cmd);
				if (access(path, X_OK))
					break;
				else
					cnt++;
			}	
		}
	}
}
