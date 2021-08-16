/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 18:42:13 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/16 19:58:23 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);	
}

int	is_base(char *base)
{
	char	*cnt;
	int		base_ok;

	base_ok = 1;
	while (*base && base_ok)
	{
		cnt = base + 1;
		if (*base == '-' || *base == '+')
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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_base_aux(int base_len, char *base, unsigned int num)
{
	int	n;

	if (num > 0)
	{
		n = num % base_len;
		ft_putnbr_base_aux(base_len, base, num / base_len);
		ft_putchar(base[n]);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				base_len;
	unsigned int	num;

	base_len = ft_strlen(base);
	if (is_base(base) && base_len > 1)
	{
		if (nbr < 0)
			ft_putchar('-');
		num = nbr;
		if (num > 0)
			ft_putnbr_base_aux(base_len, base, num);
		else
			ft_putchar(base[num]);
	}
}
