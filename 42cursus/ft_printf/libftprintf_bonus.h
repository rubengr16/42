/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 19:57:31 by rgallego          #+#    #+#             */
/*   Updated: 2021/11/01 11:50:55 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_BONUS_H
# define LIBFTPRINTF_BONUS_H

# include <unistd.h>
# include <stdarg.h>

/********************************* PRINTF *********************************** */
int	ft_printf(const char *format, ...);
int	ft_normal_bonus(char *str, va_list arg_list, int *cnt);
int	ft_conversor_bonus(char *str, va_list arg_list, int *cnt);
int	ft_conversor(char c, va_list arg_list);

/*************************** AUXILIARY FUNCTIONS **************************** */
int	ft_printf_chr(char c);
int	ft_printf_str(char *s);
int	ft_printf_ptr(void *ptr);
int	ft_printf_int(int nb);
int	ft_printf_uns(unsigned int nb);
int	ft_printf_hex(unsigned int nb);
int	ft_printf_hexup(unsigned int nb);

/***************************** FLAGS FUNCTIONS ****************************** */
int	ft_printf_sharp(unsigned int nb, char c);
int	ft_printf_space_int(int nb);
int ft_printf_space_str(char *format, char *str, int *cnt);
int	ft_printf_plus(int nb);


/***************************** FT_PUTNBR_BASE ******************************* */
int	ft_putnbr_base(unsigned long long nb, char *base, int len_base);
int	ft_strlen(char *str);
int	ft_strchr(char *str, char c);
#endif
