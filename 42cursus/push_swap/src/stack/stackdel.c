/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackdel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 20:43:57 by rgallego          #+#    #+#             */
/*   Updated: 2022/08/30 20:58:30 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stackdelall(t_stack	*stack)
{
	t_snode	*aux;

	aux = stackpop(stack);
	while(aux != NULL)
	{
		free(aux);
		aux = stackpop(stack);
	}
}
