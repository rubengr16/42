/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 16:34:29 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/12 12:23:08 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	cont;

	cont = 0;
	while (s1[cont] == s2[cont] && s1[cont] && s2[cont] && cont < (n - 1))
		cont++;
	return (s1[cont] - s2[cont]);
}
