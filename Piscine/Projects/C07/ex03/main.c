/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:38:44 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/24 09:04:28 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strjoin(int size, char	**strs, char *sep);

int	main(void)
{
	char *s[4] = {"hola", "que", "tal", "estás"};
	char *str;
	str = ft_strjoin(0, s, ", ");
	printf("%s", str);
}
