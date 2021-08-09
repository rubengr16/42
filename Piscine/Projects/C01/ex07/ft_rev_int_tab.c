/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 14:18:00 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/09 17:15:48 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	cont;
	int	aux;

	cont = 0;
	while (cont < size)
	{
		aux = tab[cont];
		tab[cont] = tab[size - 1];
		tab[size - 1] = aux;
		cont++;
		size--;
	}
}
