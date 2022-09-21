/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:09:57 by rgallego          #+#    #+#             */
/*   Updated: 2022/09/21 22:14:02 by rgallego         ###   ########.fr       */
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
		while (str && (ft_strlen(str) != lim_len
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

/*
 * function which searchs for the correct full path of the command if possible
 * INPUT:	char **set_of_paths, char **path, char *cmd, int *cnt
 * OUTPUT:	void
 */
static char	*try_path(char **set_of_paths, char *cmd)
{
	char	*path;
	int		cnt;

	cnt = 0;
	path = ft_strjoinsep(set_of_paths[cnt], cmd, "/");
	while (set_of_paths[cnt] && path && access(path, F_OK | X_OK))
	{
		free(path);
		cnt++;
		path = ft_strjoinsep(set_of_paths[cnt], cmd, "/");
	}
	if (!set_of_paths[cnt] || !path)
	{
		free(path);
		return (NULL);
	}
	free(cmd);
	return (path);
}

/*
 * function which receives a command -cmd- and the environment variables in
 * envp. It searchs for the "PATH=" variable, splits all the paths and later
 * adds them to the cmd in order to test if there is access to the required
 * commmand.
 * INPUT:	char *cmd, char **envp
 * OUTPUT:	int	:	1	command is valid
 * 					0	invalid command
 */
char	*arevalidcmds(t_cmdslist *cmds, char **envp)
{
	t_node	*aux;
	char	**set_of_paths;
	int		cnt;

	cnt = 0;
	while (envp[cnt] && !ft_strnstr(envp[cnt], "PATH=", 5))
		cnt++;
	if (!envp[cnt])
		return (NULL);
	set_of_paths = ft_split(&envp[cnt][5], ':');
	if (!set_of_paths)
		return (NULL);
	cnt = cmds->n_elem;
	while (cnt)
	{
		aux = cmdslistpop(cmds);
		aux->cmd_flag[CMD] = try_path(set_of_paths, aux->cmd_flag[CMD]);
		if (!aux->cmd_flag[CMD])
			return (NULL);
		cmdslistpush(cmds, aux);
		cnt--;
	}
	ft_free_split(set_of_paths);
	return (aux->cmd_flag[CMD]);
}
