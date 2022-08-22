/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergesort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 18:42:43 by rgallego          #+#    #+#             */
/*   Updated: 2022/08/22 21:08:28 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

static void	merge(t_vector *vector, int i_0, int k, int i_n)
{
	t_vector	*aux;
	int			pos;	
	int			i;
	int			j;

	aux = &(t_vector){(i_n - i_0 + 1), malloc(sizeof(int) * (i_n - i_0 + 1))};
	pos = 0;
	i = i_0;
	j = k + 1;
	while (i <= k && j <= i_n)
	{
		if (vector->nums[i] <= vector->nums[j])
			aux->nums[pos++] = vector->nums[i++];
		else
			aux->nums[pos++] = vector->nums[j++];
	}
	while (i <= k)
		aux->nums[pos++] = vector->nums[i++];
	while (j <= i_n)
		aux->nums[pos++] = vector->nums[j++];
	pos = 0;
	while (pos < aux->n_elem)
		vector->nums[i_0++] = aux->nums[pos++];
}

static void	sort(t_vector *vector, int i_0, int i_n)
{
	int	k;

	if (i_0 >= i_n)
		return ;
	k = (i_0 + i_n) / 2;
	sort(vector, i_0, k);
	sort(vector, k + 1, i_n);
	merge(vector, i_0, k, i_n);
}

t_vector	*merge_sort(t_queue queue)
{
	t_vector	*vector;
	t_node		*aux;
	int			i;

	vector = &(t_vector){queue.n_elem, malloc(sizeof(int) * queue.n_elem)};
	if (!vector->nums)
		return (NULL);
	aux = queue.head;
	i = 0;
	while (i < vector->n_elem)
	{
		vector->nums[i] = aux->num;
		aux = aux->next;
		i++;
	}
	sort(vector, 0, vector->n_elem - 1);
	return (vector);
}