/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 22:57:56 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/14 00:08:52 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	protected:
		std::string	_type;

	public:
/* ****************************** CONSTRUCTORS ****************************** */
		Animal(void);
		Animal(const Animal& animal);
/* ******************************* DESTRUCTOR ******************************* */
		virtual ~Animal(void);
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		Animal&				operator=(const Animal& animal);
/* **************************** MEMBER FUNCTIONS **************************** */
		const std::string&	getType(void) const;
		virtual void		makeSound(void) const;
};

#endif
