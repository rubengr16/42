/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:02:16 by rgallego          #+#    #+#             */
/*   Updated: 2021/10/15 17:07:46 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT LINE_H

#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd);
void	search_nl(char *buffer, int *n_char);
void	insert_line(char **line, char *buffer, int *n_char, int *len);
void	fill_rest(char **rest, char *buffer, int n_char);
void	read_line(char **rest, char **line, int len, int fd);

#endif
