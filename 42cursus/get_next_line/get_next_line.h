/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:02:16 by rgallego          #+#    #+#             */
/*   Updated: 2021/11/05 17:43:20 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT LINE_H

#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd);
void	read_line(char **rest, char **line, int len, int fd);
int		ft_strchr_nl(char *str, int *pos_nl);
//void	ft_strcpy(char **dest, char *src, int len);
void	ft_strcpy(char *dest, char *src, int len);
int		ft_strjoin(char **dest, char *src, int len1, int len2);
void	ft_free_resources(char **line);


#endif
