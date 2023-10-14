/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 22:59:20 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/14 22:36:41 by rgallego         ###   ########.fr       */
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
		Dog(std::string type);

	public:
		Dog(void);
		Dog(const Brain brain);
		Dog(const Dog& dog);
/* ******************************* DESTRUCTOR ******************************* */
		virtual ~Dog(void);
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		Dog&			operator=(const Dog& dog);
/* **************************** MEMBER FUNCTIONS **************************** */
		const Brain*	getBrain(void) const;
		virtual void	makeSound(void) const;
};

#endif
