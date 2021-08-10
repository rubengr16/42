/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 11:31:45 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/10 12:14:47 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_numeric(char *str);

int	main(void)
{
	char	*str;
	int	resul;

	str = "-12345678";
	resul = ft_str_is_numeric(str);
	if (resul == 1)
		printf("Is numeric %d", resul);
	else
		printf("It is not %d", resul);
}
