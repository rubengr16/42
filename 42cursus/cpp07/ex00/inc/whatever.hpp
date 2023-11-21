/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:34:28 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/21 22:24:35 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void	swap(T& a, T& b)
{
	T aux(a);

	a = b;
	b = aux;
}


template <typename T>
T	min(const T& a, const T& b)
{
	if (a < b)
		return (a);
	return (b);
}

template <typename T>
T	max(const T& a, const T& b)
{
	if (a > b)
		return (a);
	return (b);
}

#endif
