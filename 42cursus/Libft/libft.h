/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 13:02:59 by rgallego          #+#    #+#             */
/*   Updated: 2021/09/14 17:03:24 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define LLONG_MAX 9223372036854775807

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

/**************************************************************************** */
/******************************* PART 1 ************************************* */
/**************************************************************************** */

/******************************* PART 1.1 *********************************** */
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n); // all test f
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n); // libftTester
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *s);

/******************************* PART 1.2 *********************************** */
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);

/**************************************************************************** */
/******************************* PART 2 ************************************* */
/**************************************************************************** */
char	*ft_substr(char const *s, unsigned int start, size_t len); // all test f
/**** 6 left ****/
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd); // not protected
void	ft_putendl_fd(char *s, int fd); // not protected

/**************************************************************************** */
/******************************* BONUS ************************************** */
/**************************************************************************** */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

#endif
