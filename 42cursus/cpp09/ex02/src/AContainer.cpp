/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AContainer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:50:41 by rgallego          #+#    #+#             */
/*   Updated: 2024/01/16 23:53:59 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AContainer.hpp"

/* ****************************** CONSTRUCTORS ****************************** */
template <typename T<unsigned int> >
AContainer<T>::AContainer(void)
{
}

template <typename T<unsigned int> >
AContainer<T>::AContainer(char** values)
{
	std::stringstream	stream;
	long long int		value;
	unsigned int		i = 0;

	while (values[i])
	{
		stream = values[i];
		stream >> value;
		if (result != -std::numeric_limits<float>::infinity()
			&& result != std::numeric_limits<float>::infinity()
			&& (result < -std::numeric_limits<float>::max()
			|| std::numeric_limits<float>::max() < result 
			|| (errno == ERANGE && (result == -HUGE_VAL))))
			throw (AContainer::OutOfRangeResultException());
		T<unsigned int>::push_back(value);
		i++;
	}
}

template <typename T<unsigned int> >
AContainer<T>::AContainer(const AContainer& rhs)
{
}

/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
template <typename T<unsigned int> >
AContainer<T>&	AContainer<T>::operator=(const AContainer& rhs)
{
	return (*this);
}

/* ******************************* DESTRUCTOR ******************************* */
template <typename T<unsigned int> >
AContainer<T>::~AContainer(void)
{
}

/* ******************************* EXCEPTIONS ******************************* */
template <typename T<unsigned int> >
const char*	AContainer<T>::OutOfRangeResultException::what(void) const throw()
{
	return ("Error: could not represent the result number.");
}
