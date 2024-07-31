/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:59:45 by rgallego          #+#    #+#             */
/*   Updated: 2024/07/31 16:37:50 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controller.hpp"

Base*	generate(void)
{
	unsigned int	randomNb;

	std::srand(std::time(NULL));
	randomNb = std::rand() % 3;
	if (randomNb == 0)
		return (dynamic_cast<Base*>(new A));
	if (randomNb == 1)
		return (dynamic_cast<Base*>(new B));
	return (dynamic_cast<Base*>(new C));
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "p is of type A*" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "p is of type B*" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "p is of type C*" << std::endl;
	else
		std::cout << "p is of an unknown type*" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "p is of type A&" << std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			(void)dynamic_cast<B&>(p);
			std::cout << "p is of type B&" << std::endl;
		}
		catch(const std::exception& e)
		{
			try
			{
				(void)dynamic_cast<C&>(p);
				std::cout << "p is of type C&" << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cout << "p is of an unknown type" << std::endl;
			}
		}
	}
}
