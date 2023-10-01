/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:07:14 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/01 17:38:51 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl	harl;

	std::cout << "Let's try DEBUG level:"
		<< std::endl;
	harl.complain("DEBUG");
	std::cout << "Let's try INFO level:"
		<< std::endl;
	harl.complain("INFO");
	std::cout << "Let's try WARNING level:"
		<< std::endl;
	harl.complain("WARNING");
	std::cout << "Let's try ERROR level:"
		<< std::endl;
	harl.complain("ERROR");
	std::cout << "Let's try INVALID level:"
		<< std::endl;
	harl.complain("INVALID");
	return (0);
}
