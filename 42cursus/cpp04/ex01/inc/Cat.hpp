/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 22:58:32 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/14 22:47:52 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal
{
/* ****************************** CONSTRUCTORS ****************************** */
	private:
		Brain*	_brain;

	public:
		Cat(void);
		Cat(const Brain brain);
		Cat(const Cat& cat);
/* ******************************* DESTRUCTOR ******************************* */
		~Cat(void);
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		Cat&			operator=(const Cat& cat);
/* **************************** MEMBER FUNCTIONS **************************** */
		const Brain*	getBrain(void) const;
		void		makeSound(void) const;
};

#endif
