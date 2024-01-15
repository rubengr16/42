/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:28:30 by rgallego          #+#    #+#             */
/*   Updated: 2024/01/15 17:22:26 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong arguments number, please ensure: "
			<< "./RPN \"<operation>\"" << std::endl;
		return (1);
	}
	try
	{
		RPN::calculate(argv[1]);
	}
	catch (const RPN::ARPNException& e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}
