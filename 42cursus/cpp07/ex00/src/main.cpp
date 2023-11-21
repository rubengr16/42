/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:45:36 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/21 21:52:36 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

int	main( void )
{
	int	a = 2;
	int	b = 3;

	::swap(a,b);
	std::cout << "a = " << a << ", b = " << b<< std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a,b) << std::endl;
	
	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c,d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c,d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c,d) << std::endl;

	return (0);
}
