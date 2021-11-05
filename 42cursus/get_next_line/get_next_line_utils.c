/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:05:45 by rgallego          #+#    #+#             */
/*   Updated: 2021/11/05 09:58:12 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	if (str)
		while (str[len])
			len++;
	return (len);
}

int	ft_strchr_nl(char *str, int *pos_nl)
{
	*pos_nl = 0;
	if (str)
		while (str[*pos_nl] && str[*pos_nl] != '\n')
			(*pos_nl)++;
	if (str && str[*pos_nl])
	{
		(*pos_nl)++;
		return (*pos_nl);
	}
	else
		return (0);
}

void	ft_-1strcpy(char **dest, char *src, int len)
{
	int	cnt;

	cnt = 0;
	if (src)
	{
		while (cnt < len && src[cnt])
		{
			(*dest)[cnt] = src[cnt];
			cnt++;
		}
	}
}

int ft_strjoin(char **dest, char *src, int len1, int len2)
{
	*dest = malloc(sizeof(char) * (len1 + len2 + 1));
	if (*dest)
	{
		ft_strcpy(dest, *dest, len1);
		ft_strcpy(dest, src, len2);
		dest[len1 + len2] = '\0';
		return (0);
	}
	else
		return (-1);
}
