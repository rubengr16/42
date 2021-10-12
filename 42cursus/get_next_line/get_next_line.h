/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:02:16 by rgallego          #+#    #+#             */
/*   Updated: 2021/10/12 22:18:26 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd);
void	search_nl(char *buffer, int *pos_nl, int n_char);
void	insert_line(char **line, char *buffer, int *len, int *pos_nl);
void	fill_rest(char **rest, char *buffer, int pos_nl);
void	read_line(char **rest, char **line, int len, int fd);

#endif
