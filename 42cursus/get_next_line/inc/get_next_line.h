/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:02:16 by rgallego          #+#    #+#             */
/*   Updated: 2021/11/08 16:23:51 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

/******************************* GET_NEXT_LINE ***************************** */
char	*get_next_line(int fd);

/*************************** GET_NEXT_LINE_UTILS *************************** */
int		ft_strchr_nl(char *str, int *pos_nl);
void	ft_strcpy(char *dest, char *src, int len);
int		ft_strjoin(char **dest, char *src, int len1, int len2);
void	ft_free_resources(char **line);
void	read_line(char **rest, char **line, int len, int fd);

#endif
