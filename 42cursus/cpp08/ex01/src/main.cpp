/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:28:30 by rgallego          #+#    #+#             */
/*   Updated: 2023/12/22 20:07:43 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "utils.hpp"

int	main(void)
{
	Span	sp = Span(5);
	Span	spInc = Span(10000);
	Span	spRand = Span(10000);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	sp.print();
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	try
	{
		sp.addNumber(10, incGenerator);
	}
	catch(const Span::VectorIsFullException& e)
	{
		std::cerr << e.what() << std::endl;
	}

	spInc.addNumber(10000, incGenerator);
	std::cout << spInc.shortestSpan() << std::endl;
	std::cout << spInc.longestSpan() << std::endl;
	spInc.print();


	std::srand(std::time(NULL));
	spRand.addNumber(10000, randGenerator);
	std::cout << spRand.shortestSpan() << std::endl;
	std::cout << spRand.longestSpan() << std::endl;
	spRand.print();

	return (0);
}
