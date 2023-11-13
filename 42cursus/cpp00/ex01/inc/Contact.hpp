/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 22:17:13 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/14 00:05:45 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>

class	Contact
{
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phone;
		std::string	_darkestSecret;

	public:
		Contact();
		Contact(std::string firstName, std::string lastName,
			std::string nickname, std::string phone,
			std::string  darkestSecret);
		~Contact(void);
		void				setFirstName(std::string firstName);
		const std::string&	getFirstName(void) const;
		void				setLastName(std::string lastName);
		const std::string&	getLastName(void) const;
		void				setNickname(std::string nickname);
		const std::string&	getNickname(void) const;
		void				setPhone(std::string phone);
		const std::string&	getPhone(void) const;
		void				setDarkestSecret(std::string darkestSecret);
		const std::string&	getDarkestSecret(void) const;
		void				setAll(std::string firstName, std::string lastName,
			std::string nickname, std::string phone,
			std::string  darkestSecret);
		void				printContact(void);
};

#endif
