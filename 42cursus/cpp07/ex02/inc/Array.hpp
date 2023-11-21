/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:34:28 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/21 23:49:55 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array
{
	private:
		T*				_array[];
		unsigned int	_size;

	public:
		Array(void):
			_array(),
			_size(0)
		{
			
		}

		Array(unsigned int size)
			_array(new T[size]),
			_size(size)
		{
			
		}

		~Array(void)
		{
		}
};

#endif
