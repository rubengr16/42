/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 11:31:45 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/10 12:28:53 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_uppercase(char *str);

int	main(void)
{
	char	*str;
	int		resul;

	str = "ASDFGHJ";
	resul = ft_str_is_uppercase(str);
	if (resul == 1)
		printf("Is uppercase %d", resul);
	else
		printf("It is not %d", resul);
}
