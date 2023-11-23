/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:28:41 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/23 20:25:39 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>

/* ******************************* EXCEPTIONS ******************************* */
class ElemNotFoundException: public std::exception
{
	public:
		virtual const char*	what(void) const throw()
		{
			return ("[What] EasyFind: Error! Elem Not Found");
		}
};

/* *************************** TEMPLATED FUNCTION *************************** */
template <typename T>
typename T::iterator	easyfind(T& container, int wanted)
{
	typename T::iterator	result = std::find(container.begin(),
		container.end(), wanted);

	if (result == container.end())
		throw (ElemNotFoundException());
	return (result);
}

#endif
