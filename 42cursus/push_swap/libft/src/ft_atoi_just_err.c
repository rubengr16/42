/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_just_err.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:02:07 by rgallego          #+#    #+#             */
/*   Updated: 2023/02/23 10:06:23 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * function which receives a string with a number writen in ASCII and returns
 * the integer representation of it. Returns and exits if invalid number is
 * given.
 * INPUT:	const char *s
 * OUTPUT:	int
 */
int	ft_atoi_just_err(const char *s)
{
	int					sign;
	unsigned long long	num;

	sign = 1;
	num = 0;
	while (*s && (*s == '\t' || *s == '\n' || *s == '\v' || *s == '\f'
			|| *s == '\r' || *s == ' '))
		s++;
	if (*s == '-')
		sign = -1;
	if (*s == '-' || *s == '+')
		s++;
	if (!ft_isdigit(*s))
		ft_error("Error", STDERR_FILENO, ERR_USR);
	while (*s && '0' <= *s && *s <= '9')
	{
		num = num * 10 + (*s - '0');
		s++;
	}
	if (*s && !ft_isdigit(*s))
		ft_error("Error", STDERR_FILENO, ERR_USR);
	if ((sign == -1 && num > INT_MAX) || (sign == 1 && num >= INT_MAX))
		ft_error("Error", STDERR_FILENO, ERR_USR);
	return (sign * num);
}
