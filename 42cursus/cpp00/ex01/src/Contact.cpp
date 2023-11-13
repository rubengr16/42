/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 22:47:09 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/28 15:51:47 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
}

Contact::Contact(std::string firstName, std::string lastName,
	std::string nickname, std::string phone,std::string  darkestSecret)
{
	this->_firstName = firstName;
	this->_lastName = lastName;
	this->_nickname = nickname;
	this->_phone = phone;
	this->_darkestSecret = darkestSecret;
}

Contact::~Contact(void)
{
}

void	Contact::setFirstName(std::string firstName)
{
	this->_firstName = firstName;
}
std::string	Contact::getFirstName(void) const
{
	return (this->_firstName);
}

void		Contact::setLastName(std::string lastName)
{
	this->_lastName = lastName;
}

std::string	Contact::getLastName(void) const
{
	return (this->_lastName);
}

void	Contact::setNickname(std::string nickname)
{
	this->_nickname = nickname;
}

std::string	Contact::getNickname(void) const
{
	return (this->_nickname);
}

void	Contact::setPhone(std::string phone)
{
	this->_phone = phone;
}

std::string	Contact::getPhone(void) const
{
	return (this->_phone);
}

void	Contact::setDarkestSecret(std::string darkestSecret)
{
	this->_darkestSecret = darkestSecret;
}

std::string	Contact::getDarkestSecret(void) const
{
	return (this->_darkestSecret);
}

void	Contact::setAll(std::string firstName, std::string lastName,
std::string nickname, std::string phone,std::string  darkestSecret)
{
	this->_firstName = firstName;
	this->_lastName = lastName;
	this->_nickname = nickname;
	this->_phone = phone;
	this->_darkestSecret = darkestSecret;
}

void	Contact::printContact(void)
{
	std::cout << "FIRST NAME: " << this->_firstName << std::endl;
	std::cout << "LAST NAME: " << this->_lastName << std::endl;
	std::cout << "NICKNAME: " << this->_firstName << std::endl;
	std::cout << "FIRST NAME: " << this->_nickname << std::endl;
	std::cout << "PHONE: " << this->_phone << std::endl;
	std::cout << "DARKEST SECRET: " << this->_darkestSecret << std::endl;
}
