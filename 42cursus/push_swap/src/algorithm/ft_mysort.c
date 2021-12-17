/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mysort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:00:20 by rgallego          #+#    #+#             */
/*   Updated: 2021/12/17 19:24:59 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sortbase_a(t_queue *a)
{
	if (!ft_issorted(a))
	{
		if (a->head < a->head->next && a->head->next > a->head->prvs)
			ft_reverse_rotate_a(a);
		else if (a->head->next < a->head && a->head > a->head->prvs)
			ft_rotate_a(a);
		if (!ft_issorted(a))
			ft_swap_a(a);	
	}
}
