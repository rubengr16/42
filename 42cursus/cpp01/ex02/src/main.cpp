/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:17:20 by rgallego          #+#    #+#             */
/*   Updated: 2023/09/29 19:18:29 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	message = "HI THIS IS BRAIN";
	std::string	*stringPTR = &message;
	std::string	&stringREF = message;

	std::cout << "Address of message: " << &message
		<< std::endl;
	std::cout << "Address of stringPTR: " << stringPTR
		<< std::endl;
	std::cout << "Address of stringREF: " << &stringREF
		<< std::endl;
	std::cout << "Value of message: " << message
		<< std::endl;
	std::cout << "Value of stringPTR: " << *stringPTR
		<< std::endl;
	std::cout << "Value of stringREF: " << stringREF
		<< std::endl;
	return (0);
}
