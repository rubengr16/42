/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:31:04 by rgallego          #+#    #+#             */
/*   Updated: 2021/09/27 21:13:19 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_count_words(char	const *s, char c)
{
	int	n_words;
	int	i;

	n_words = 0;
	i = 0;
	if (s[i] != c)
		n_words = 1;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
		   n_words++;
		i++;
	}
	return (n_words);
}

static char	*ft_put_word(const char *s, char c, int	*pos)
{
	int		len;
	int		cnt;
	char	*word;

	len = 0;
	cnt = 0;
	while (s[*pos] == c)
		(*pos)++;
	while (s[len] && s[len] != c)
		len++;
	word = malloc(sizeof(char) * (len + 1));
	if (word)
	{
		while (s[*pos] && s[*pos] != c)
		{
			word[cnt] = s[*pos];
			(*pos)++;
			cnt++;
		}
		word[cnt] = '\0';
	}
	return (word);
}

static char	**ft_reset(char	**res, int	i)
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
	int		pos;	
	int		i;

	if (!s)
		return (NULL);
	n_words = ft_count_words(s, c);
	res = malloc(sizeof(char *) * (n_words + 1));
	if (!res)
		return (NULL);
	i = 0;
	pos = 0;
	while (s[pos] && i < n_words)
	{
		res[i] = ft_put_word(s, c, &pos);
		if (!res[i])
			return (ft_reset(res, i - 1));
		i++;
	}
	res[i] = NULL;
	return (res);
}
