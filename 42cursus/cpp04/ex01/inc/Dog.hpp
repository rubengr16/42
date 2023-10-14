/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 22:59:20 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/13 00:22:14 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"

class Dog: public Animal
{
/* ****************************** CONSTRUCTORS ****************************** */
	private:
		Dog(std::string type);

	public:
		Dog(void);
		Dog(const Dog& dog);
/* ******************************* DESTRUCTOR ******************************* */
		~Dog(void);
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		Dog&			operator=(const Dog& dog);
/* **************************** MEMBER FUNCTIONS **************************** */
		virtual void	makeSound(void) const;
};

#endif
