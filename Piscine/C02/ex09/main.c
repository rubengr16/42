/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:00:31 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/10 15:36:37 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcapitalize(char *str);

int	main(void)
{
	char	str[] = "salut, comment tu vas ? 42mots quaRante-deux; cinquante+et+un";

	printf("%s\n", str);
	printf("%s", ft_strcapitalize(str));
}
