/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 23:47:22 by rgallego          #+#    #+#             */
/*   Updated: 2023/09/14 00:08:15 by rgallego         ###   ########.fr       */
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

	firstName = Contact::getField("Enter your contact's first name: ");
	lastName = Contact::getField("Enter your contact's last name: ");
	nickname = Contact::getField("Enter your contact's nickname: ");
	phone = Contact::getField("Enter your contact's phone: ");
	darkestSecret = Contact::getField("Enter your contact's darkest secret: ");
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
	int		n;

	std::cout << std::setfill(' ') << std::setw(10) << "INDEX" << '|';
	std::cout << std::setfill(' ') << std::setw(10) << "FIRST NAME" << '|';
	std::cout << std::setfill(' ') << std::setw(10) << "LAST NAME" << '|';
	std::cout << std::setfill(' ') << std::setw(10) << "NICKNAME" << std::endl;
	first = (this->_last - this->_size + 1) % 8;
	n = 0;
	do
	{
		std::cout << std::setfill(' ') << std::setw(10) << n << '|';
		std::cout << std::setfill(' ') << std::setw(10) 
			<< this->_contacts[(first + n) % this->_MAX_SIZE].getFirstName()
			<< '|';
		std::cout << std::setfill(' ') << std::setw(10) 
			<< this->_contacts[(first + n) % this->_MAX_SIZE].getLastName()
			<< '|';
		std::cout << std::setfill(' ') << std::setw(10) 
			<< this->_contacts[(first + n) % this->_MAX_SIZE].getNickname()
			<< std::endl;
		n++;
	} while (n < this->_size);
	
}
