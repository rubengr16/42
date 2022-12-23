/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_prep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 18:42:43 by rgallego          #+#    #+#             */
/*   Updated: 2022/12/23 17:29:05 by rgallego         ###   ########.fr       */
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
	free(aux->nums);
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

static t_vector	*merge_sort(t_queue queue)
{
	t_vector	*vector;
	t_qnode		*aux;
	int			i;

	vector = malloc(sizeof(t_vector));
	if (!vector)
		return (NULL);
	vector->n_elem = queue.n_elem;
	vector->nums = malloc(sizeof(int) * vector->n_elem);
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

static int	binary_search(t_vector *vector, int num, int i_0, int i_n)
{
	int	k;

	if (i_0 == i_n && num == vector->nums[i_0])
		return (i_0);
	if (i_0 == i_n && num != vector->nums[i_0])
		return (-1);
	k = (i_0 + i_n) / 2;
	if (num < vector->nums[k])
		return (binary_search(vector, num, i_0, k - 1));
	if (num > vector->nums[k])
		return (binary_search(vector, num, k + 1, i_n));
	return (k);
}

void	algorithm_prep(t_queue queue, t_stack *stack)
{
	t_vector	*vector;
	t_qnode		*aux;

	vector = merge_sort(queue);
	aux = queue.head;
	aux->num = binary_search(vector, aux->num, 0, (vector->n_elem - 1));
	aux = aux->next;
	while (aux != queue.head)
	{
		aux->num = binary_search(vector, aux->num, 0, (vector->n_elem -1));
		aux = aux->next;
	}
	stackpush_minmax(stack, 1, queue.n_elem);
	free(vector->nums);
	free(vector);
}
