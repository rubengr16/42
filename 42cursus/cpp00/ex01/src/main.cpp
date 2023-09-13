/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 23:08:05 by rgallego          #+#    #+#             */
/*   Updated: 2023/09/13 23:43:32 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(void)
{
	PhoneBook	phoneBook;
	std::string	command;

	std::cout << "Welcome to the 42 awesome phone book!!" << std::endl;
	do
	{
		std::cout << "Please, enter your command: ";
		std::getline(std::cin, command);
		if (!command.compare("ADD"))
			phoneBook.addContact();
		else if (!command.compare("SEARCH"))
			phoneBook.searchContact();
	} while (command.compare("EXIT"));
	return (0);
}
