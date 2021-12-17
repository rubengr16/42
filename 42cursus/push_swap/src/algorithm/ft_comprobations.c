/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comprobations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 19:00:58 by rgallego          #+#    #+#             */
/*   Updated: 2021/12/17 19:07:28 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_issorted(t_queue *queue)
{
	t_node	*aux;

	aux = queue->head->next;
	while (aux != queue->head && aux->next > aux)
		aux = aux->next;
	if (aux == queue->head)
		return (1);
	else
		return (0);
}
