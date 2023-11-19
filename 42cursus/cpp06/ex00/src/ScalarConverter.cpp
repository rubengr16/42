/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 23:41:21 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/19 11:25:05 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* ****************************** CONSTRUCTORS ****************************** */
ScalarConverter::ScalarConverter(void)
{
	std::cout << "[Default Constructor] ScalarConverter: shall never be used"
	<< std::endl << "----------------------------------------------------"
	<< std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& scalarConverter)
{
	(void)scalarConverter;
	std::cout << "[Copy Constructor] ScalarConverter: shall never be used"
	<< std::endl << "----------------------------------------------------"
	<< std::endl;
}

/* ******************************* DESTRUCTOR ******************************* */
ScalarConverter::~ScalarConverter()
{
	std::cout << "[Destructor] ScalarConverter: shall never be used"
	<< std::endl << "----------------------------------------------------"
	<< std::endl;
}

/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
ScalarConverter&	ScalarConverter::operator=(
	const ScalarConverter& scalarConverter)
{
	(void)scalarConverter;
	std::cout << "[Copy Assignment Operator] ScalarConverter: shall never be "
	" used" << std::endl
	<< "----------------------------------------------------" << std::endl;
}

/* **************************** MEMBER FUNCTIONS **************************** */
void	ScalarConverter::conversion(const std::string& input)
{
	
}

void	ScalarConverter::conversion(const std::string& input, char& c)
{

}

void	ScalarConverter::conversion(const std::string& input, int& nb)
{

}

void	ScalarConverter::conversion(const std::string& input, float& flt)
{

}

void	ScalarConverter::conversion(const std::string& input, double& dbl)
{
	
}
