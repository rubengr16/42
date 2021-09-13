/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 12:52:13 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/17 09:34:27 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char *str)
{
	int	resul;

	resul = 0;
	if (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\r'
		|| *str == ' ')
		resul = 1;
	return (resul);
}

int	ft_is_number(char *str)
{
	int	resul;

	resul = 0;
	if ('0' <= *str && *str <= '9')
		resul = 1;
	return (resul);
}

char	*ignore_space(char *str)
{
	while (*str && ft_isspace(str))
		str++;
	return (str);
}

char	*ft_sign(char *str, int	*count)
{
	while (*str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			(*count)++;
		str++;
	}
	*count %= 2;
	return (str);
}

int	ft_atoi(char *str)
{
	int			sign;
	long		nb;

	nb = 0;
	sign = 0;
	str = ignore_space(str);
	str = ft_sign(str, &sign);
	while (*str && ft_is_number(str))
	{
		nb = (nb * 10) + (*str - '0');
		str++;
	}
	if (sign)
	{
		nb *= -1;
		sign = 0;
	}
	return ((int)nb);
}
