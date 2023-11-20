/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 23:19:09 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/20 23:29:18 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/* ****************************** CONSTRUCTORS ****************************** */
Serializer::Serializer(void)
{
	std::cout << "[Default Constructor] Serializer: shall never be used"
	<< std::endl << "----------------------------------------------------"
	<< std::endl;
}

Serializer::Serializer(const Serializer& serializer)
{
	(void)serializer;
	std::cout << "[Copy Constructor] Serializer: shall never be used"
	<< std::endl << "----------------------------------------------------"
	<< std::endl;
}

/* ******************************* DESTRUCTOR ******************************* */
Serializer::~Serializer()
{
	std::cout << "[Destructor] Serializer: shall never be used"
	<< std::endl << "----------------------------------------------------"
	<< std::endl;
}

/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
Serializer&	Serializer::operator=(const Serializer& serializer)
{
	(void)serializer;
	std::cout << "[Copy Assignment Operator] Serializer: shall never be "
	" used" << std::endl
	<< "----------------------------------------------------" << std::endl;
	return (*this);
}

/* **************************** MEMBER FUNCTIONS **************************** */
uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*		Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
