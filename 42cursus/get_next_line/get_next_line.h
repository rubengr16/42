/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:02:16 by rgallego          #+#    #+#             */
/*   Updated: 2021/11/04 11:24:41 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT LINE_H

#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd);
int		ft_strlen(char *str, int *len, int *pos_nl);
int		ft_strjoin(char **dest, char *src, int *len, int pos_nl);
void	fill_rest(char **rest, char *buffer, int len, int start);
//void	free_line(char **line);
void	read_line(char **rest, char **line, int len, int fd);

#endif
