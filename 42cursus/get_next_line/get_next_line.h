/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:02:16 by rgallego          #+#    #+#             */
/*   Updated: 2021/10/19 13:02:05 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT LINE_H

#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd);
void	old_line_cpy(char **line, char *aux);
void	new_line_cpy(char **line, char *buffer, int n_char, int *len);
void	insert_line(char **line, char *buffer, int *n_char, int *len);
void	fill_rest(char **rest, char *buffer, int n_char);
void	read_line(char **rest, char **line, int len, int fd);

#endif
