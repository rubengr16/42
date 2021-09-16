/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:44:03 by rgallego          #+#    #+#             */
/*   Updated: 2021/09/16 14:45:58 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*aux;

	if (lst)
	{
		if (*lst)
		{
			aux = ft_lstlast(*lst);
			aux->next = new;
		}
		else
			*lst = new;
	}
}
