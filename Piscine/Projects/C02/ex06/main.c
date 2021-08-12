/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 11:31:45 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/12 11:25:10 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str);

int	main(void)
{
	char	*str;
	int		resul;

	str = "ASDFGHJ";
	resul = ft_str_is_printable(str);
	if (resul == 1)
		printf("Is printable %d", resul);
	else
		printf("It is not %d", resul);
}
