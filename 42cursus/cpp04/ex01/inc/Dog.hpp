/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 22:59:20 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/17 15:28:06 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal
{
/* ****************************** CONSTRUCTORS ****************************** */
	private:
		Brain*	_brain;

	public:
		Dog(void);
		Dog(const Brain& brain);
		Dog(const Dog& dog);
/* ******************************* DESTRUCTOR ******************************* */
		~Dog(void);
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		Dog&			operator=(const Dog& dog);
/* **************************** MEMBER FUNCTIONS **************************** */
		const Brain*	getBrain(void) const;
		void			makeSound(void) const;
};

#endif
