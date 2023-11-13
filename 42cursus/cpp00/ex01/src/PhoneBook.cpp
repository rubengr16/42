/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 23:47:22 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/02 18:28:59 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void): _MAX_SIZE(8)
{
	this->_size = 0;
	this->_last = -1;
}

PhoneBook::~PhoneBook(void)
{
}

void	PhoneBook::addContact(void)
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phone;
	std::string	darkestSecret;

	firstName = getField("Enter your contact's first name: ");
	lastName = getField("Enter your contact's last name: ");
	nickname = getField("Enter your contact's nickname: ");
	phone = getField("Enter your contact's phone: ");
	darkestSecret = getField("Enter your contact's darkest secret: ");
	this->_last = (this->_last + 1) % this->_MAX_SIZE;
	this->_contacts[this->_last].setAll(firstName, lastName, nickname,
		phone, darkestSecret);
	this->_size = (this->_size + 1);
	if (this->_MAX_SIZE <= this->_size)
		this->_size = this->_MAX_SIZE;
}

void	PhoneBook::searchContact(void)
{
	int		first;
	int		i;
	int		n;

	std::cout << std::setfill(' ') << std::setw(10) << "INDEX" << '|';
	std::cout << std::setfill(' ') << std::setw(10) << "FIRST NAME" << '|';
	std::cout << std::setfill(' ') << std::setw(10) << "LAST NAME" << '|';
	std::cout << std::setfill(' ') << std::setw(10) << "NICKNAME" << std::endl;
	first = (this->_last - this->_size + 1) % this->_MAX_SIZE;
	if (first < 0)
		first += this->_MAX_SIZE;
	n = 0;
	while (n < this->_size)
	{
		std::cout << std::setfill(' ') << std::setw(10) << n << '|';
		std::cout << std::setfill(' ') << std::setw(10) 
			<< formatField(this->_contacts[(first + n) % this->_MAX_SIZE].getFirstName())
			<< '|';
		std::cout << std::setfill(' ') << std::setw(10) 
			<< formatField(this->_contacts[(first + n) % this->_MAX_SIZE].getLastName())
			<< '|';
		std::cout << std::setfill(' ') << std::setw(10) 
			<< formatField(this->_contacts[(first + n) % this->_MAX_SIZE].getNickname())
			<< std::endl;
		n++;
	}
	std::cout << "Please, select an index to see full contact information (choose -1 to avoid it): ";
	std::cin >> i;
	while (!std::cin.good() || (i < -1 || i >= this->_size))
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		std::cout << "Invalid index, please enter a valid option" << std::endl;
		std::cout << "Please, select an index to see full contact information (choose -1 to avoid it): ";
		std::cin >> i;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	if (i != -1)
		this->_contacts[(first + i) % this->_MAX_SIZE].printContact();
}
