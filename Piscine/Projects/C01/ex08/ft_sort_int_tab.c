/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 16:30:27 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/09 16:58:28 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	aux;

	aux = *a;
	*a = *b;
	*b = aux;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	cont1;
	int	cont2;

	cont1 = size - 1;
	while (0 < cont1)
	{
		cont2 = size - 1;
		while (0 < cont2)
		{
			if (tab[cont2] < tab[cont2 - 1])
				ft_swap(&tab[cont2], &tab[cont2 - 1]);
			cont2--;
		}
		cont1--;
	}
}
