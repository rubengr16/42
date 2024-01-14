/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:28:30 by rgallego          #+#    #+#             */
/*   Updated: 2024/01/14 15:25:24 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong arguments number, please ensure: ./btc <filename>"
			<< std::endl;
		return (1);
	}
	try
	{
		BitcoinExchange btcExchange;
		btcExchange;
	}
	catch(const BitcoinExchange::WrongDateException& e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	catch(const BitcoinExchange::ABitcoinExchangeException& e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}
