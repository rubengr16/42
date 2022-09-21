/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:09:57 by rgallego          #+#    #+#             */
/*   Updated: 2022/09/21 22:02:59 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_msg(t_args args, char *str, int error)
{
	if (error == ERR_ARGC)
	{
		ft_putendl_fd("Please, enter 4 arguments with the structure:", \
				STDERR_FILENO);
		ft_putendl_fd("./pipex <file1> <cmd1> <cmd2> <file2>", STDERR_FILENO);
	}
	else if (error == ERR_SPLIT)
		ft_putendl_fd("Split failed", STDERR_FILENO);
	else if (error == ERR_CMD || error == ERR_PIPE || error == ERR_OPEN)
		perror(str);
	if (args.fdin >= 0)
		close(args.fdin);
	if (args.fdout >= 0)
		close(args.fdout);
	exit(errno);
}

static void	files_mngment(t_args *args, char *fin, char *fout)
{
	char			*str;
	unsigned long	lim_len;

	if (args->limiter)
	{
		args->fdin = open(fin, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		lim_len = ft_strlen(args->limiter);
		str = get_next_line(STDIN_FILENO);
		while(str && (ft_strlen(str) != lim_len
			|| ft_strncmp(str, args->limiter, lim_len)))
		{
			write(args->fdin, str, ft_strlen(str));
			str = get_next_line(STDIN_FILENO);
		}
		close(args->fdin);
	}
	args->fdout = open(fout, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (args->fdout < 0)
		error_msg(*args, fout, ERR_OPEN);
	args->fdin = open(fin, O_RDONLY);
	if (args->fdin < 0)
		error_msg(*args, fin, ERR_OPEN);
}

/*
 * function which receives argv to divide the given commands into command
 * and flag. Each command and its flag is stored in the list. After the
 * storing process, the fin and fout are opened.
 * INPUT:	t_args *args, char **argv
 * OUTPUT:	void
 */
void	preparate_pipex(t_args *args, char **argv)
{
	char	**aux;
	char	*fin;
	int		i;

	i = 2;
	fin = argv[1];
	if (ft_strlen(fin) == ft_strlen(HERE_DOC)
		&& !ft_strncmp(fin, HERE_DOC, ft_strlen(HERE_DOC)))
	{
		fin = PATH_DOC;
		args->limiter = argv[2];
		i++;
	}
	args->cmds = cmdslistinit();
	while (argv[i] && argv[i + 1])
	{
		aux = ft_split(argv[i], ' ');
		if (!aux)
			error_msg(*args, NULL, ERR_SPLIT);
		cmdslistpush_cmd(args->cmds, aux);
		i++;
	}
	files_mngment(args, fin, argv[i]);
}

char	*ft_strjoinsep(char const *s1, char const *s2, char *c)
{
	int		len;
	char	*s;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 2;
	s = malloc(sizeof(char) * (len));
	if (!s)
		return (NULL);
	(void)ft_strlcpy(s, s1, len);
	(void)ft_strlcat(s, c, len);
	(void)ft_strlcat(s, s2, len);
	return (s);
}
