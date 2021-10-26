/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 19:57:31 by rgallego          #+#    #+#             */
/*   Updated: 2021/10/26 11:03:49 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>

/********************************* PRINTF *********************************** */
int	ft_printf(const char *format, ...);
int	ft_conversor(char c, va_list arg_list);

/*************************** AUXILIARY FUNCTIONS **************************** */
int	ft_printf_chr(char c);
int	ft_printf_str(char *s);
int	ft_printf_ptr(void *ptr);
int	ft_printf_int(int nb);
int	ft_printf_uns(unsigned int nb);
int	ft_printf_hex(unsigned int nb);
int	ft_printf_hexup(unsigned int nb);

/***************************** FT_PUTNBR_BASE ******************************* */
int	ft_putnbr_base(unsigned long long nb, char *base, int len_base);
#endif
