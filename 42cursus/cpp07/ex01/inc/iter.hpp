/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:34:28 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/21 21:59:55 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_CPP
# define ITER_CPP

template <typename T>
void	iter(T* array, unsigned int len, void (*f)(T*))
{
	unsigned int	i;

	for (i = 0; i < len; i++)
		f(&array[i]);
}

#endif
