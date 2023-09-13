/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 22:17:13 by rgallego          #+#    #+#             */
/*   Updated: 2023/09/13 23:21:47 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

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
		void		setFirstName(std::string firstName);
		std::string	getFirstName(void) const;
		void		setLastName(std::string lastName);
		std::string	getLastName(void) const;
		void		setNickname(std::string nickname);
		std::string	getNickname(void) const;
		void		setPhone(std::string phone);
		std::string	getPhone(void) const;
		void		setDarkestSecret(std::string darkestSecret);
		std::string	getDarkestSecret(void) const;
		void		setAll(std::string firstName, std::string lastName,
			std::string nickname, std::string phone,
			std::string  darkestSecret);
		static std::string	getField(std::string message);
};

#endif
