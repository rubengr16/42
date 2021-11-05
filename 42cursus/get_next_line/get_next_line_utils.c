/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:05:45 by rgallego          #+#    #+#             */
/*   Updated: 2021/11/04 15:36:28 by rgallego         ###   ########.fr       */
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

void	ft_strcpy(char **dest, char *src, int len)
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
		(*dest)[cnt] = '\0';
	}
}

int ft_strdup(char **dest, char *src, int len)
{
	*dest = malloc(sizeof(char) * (len + 1));
	if (*dest)
		ft_strcpy(dest, src, len);

}
