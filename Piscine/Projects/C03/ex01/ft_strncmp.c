/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 16:34:29 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/11 18:15:05 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int	cont;

	cont = 0;
	while (s1[cont] == s2[cont] && s1[cont] && s2[cont] && cont < n)
		cont++;
	return (s1[cont] - s2[cont]);
}
