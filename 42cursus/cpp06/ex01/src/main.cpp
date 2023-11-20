/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 23:19:06 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/20 23:45:47 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"

int	main(void)
{
	Data		data = {100};
	Data*		dataPtr;
	uintptr_t	ptr;

	ptr = Serializer::serialize(&data);
	std::cout << "serialize(&data) = " << ptr << std::endl;
	dataPtr = Serializer::deserialize(ptr);
	std::cout << "deserialize(ptr) = " << dataPtr << std::endl;
	std::cout << "original value = " << data.nb << std::endl
		<< "deserialized value = " << dataPtr->nb << std::endl;
	return (0);
}
