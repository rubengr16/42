/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 09:28:33 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/17 11:06:49 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_base(char *base)
{
	char	*cnt;
	int		base_ok;

	base_ok = 1;
	while (*base && base_ok)
	{
		cnt = base + 1;
		if (*base == '-' || *base == '+' || *base == ' ')
			base_ok = 0;
		while (base_ok && *cnt)
		{
			if (*base == *cnt)
				base_ok = 0;
			cnt++;
		}
		base++;
	}
	return (base_ok);
}

int	ft_in_base(char *str, char *base)
{
	int	pos;
	int	cnt;

	pos = -1;
	cnt = 0;
	while (*str && base[cnt] && pos == -1)
	{
		if (base[cnt] == *str)
			pos = cnt;
		cnt++;
	}
	return (pos);
}

char	*ignore_space(char *str)
{
	while (*str && (*str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\r' || *str == ' '))
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

int	ft_atoi_base(char *str, char *base)
{
	int		base_len;
	int		sign;
	int		n;
	long	nb;

	base_len = 0;
	nb = 0;
	while (base[base_len])
		base_len++;
	if (is_base(base) && base_len > 1)
	{
		str = ignore_space(str);
		str = ft_sign(str, &sign);
		n = ft_in_base(str, base);
		while (*str && n > -1)
		{
			nb = nb * base_len + n;
			str++;
			n = ft_in_base(str, base);
		}
		if (sign)
			nb *= -1;
	}
	return (nb);
}
