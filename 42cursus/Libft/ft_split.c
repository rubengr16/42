/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:31:04 by rgallego          #+#    #+#             */
/*   Updated: 2021/09/27 21:29:19 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_count_words(char const *s, char c)
{
	int	cnt;

	cnt = 0;
	if (*s != c)
		cnt++;
	else
		while (*s == c)
			s++;
	while (*s)
	{
		if (*s == c && *(s + 1) != c)
			cnt++;
		s++;
	}
	return (cnt);
}

static int	ft_word_len(const char *s, char c)
{
	int	len;

	len = 0;
	while (*s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static char	*ft_insert_word(const char *s, char c, int *cnt)
{
	char	*res;
	int		i;

	while (s[*cnt] == c)
		(*cnt)++;
	res = malloc(sizeof(char) * (ft_word_len(&s[*cnt], c)));
	if (res)
	{
		i = 0;
		while (s[*cnt] != c)
		{
			res[i] = s[*cnt];
			i++;
			(*cnt)++;
		}
		res[i] = '\0';
	}
	return (res);
}

static char	**ft_reset(char	**res, int i)
{
	while (0 <= i)
	{
		free(res[i]);
		i--;
	}
	free(res);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		n_words;
	int 	cnt;
	int		i;

	if (!s)
		return (NULL);
	n_words = ft_count_words(s, c);
	res = malloc(sizeof(char *) * (n_words + 1));
	if (res)
	{
		cnt = 0;
		i = 0;
		res[i] = ft_insert_word(s, c, &cnt);
		i++;
		while (s[cnt] && res[i - 1] && i < n_words)
		{
			res[i] = ft_insert_word(s, c, &cnt);
			i++;
		}
		if (i < n_words && res[i - 1])
			return (ft_reset(res, i - 2));
		res[i] = NULL;
	}
	return (res);
}