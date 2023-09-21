/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 22:17:16 by rgallego          #+#    #+#             */
/*   Updated: 2023/09/20 00:06:29 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PGONE_BOOK_HPP

# include "Contact.hpp"
# include "Utils.hpp"

class PhoneBook
{
	private:
		Contact		_contacts[8];
		int			_size;
		int			_last;
		int	const	_MAX_SIZE;
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	addContact(void);
		void	searchContact(void);
};

#endif
