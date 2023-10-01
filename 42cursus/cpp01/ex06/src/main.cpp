/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:07:14 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/01 23:43:31 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl	harl;

	if (argc < 2)
	{
		std::cout << "Please, enter an argument."
			<< std::endl;
		return (1);
	}
	harl.complain(argv[LEVEL]);
	return (0);
}
