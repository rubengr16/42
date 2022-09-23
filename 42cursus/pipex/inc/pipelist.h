/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipelist.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:19:13 by rgallego          #+#    #+#             */
/*   Updated: 2022/09/21 22:15:32 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPELIST_H
# define PIPELIST_H

# include <stdlib.h>
# include "libft.h"

/*************************** COMMAND STRUCTURE ****************************** */
# define CMD 0
# define FLAG 1

/************************** PIPELIST STRUCTURE ****************************** */
typedef struct s_pipe
{
	int				pipe[2];
	struct s_pipe	*next;
}	t_pipe;

typedef struct s_pipelist
{
	int		n_elem;
	t_pipe	*head;
	t_pipe	*tail;
}	t_pipelist;

/************************* PIPELIST FUNCTIONS ****************************** */
t_pipelist	*pipelistinit(void);
t_pipelist	*pipelistinitpush(int n);
t_pipe		*newpipe(void);
t_pipelist	*pipelistpush(t_pipelist *list);
t_pipelist	*pipelistpush_pipe(t_pipelist *list, t_pipe *pipe);
t_pipe		*pipelistpop(t_pipelist *list);
void		pipelistdelone(t_pipelist *list);
void		pipelistdelall(t_pipelist *list);

#endif
