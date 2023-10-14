/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 22:58:32 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/13 00:22:18 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"

class Cat: public Animal
{
/* ****************************** CONSTRUCTORS ****************************** */
	private:
		Cat(std::string type);

	public:
		Cat(void);
		Cat(const Cat& cat);
/* ******************************* DESTRUCTOR ******************************* */
		~Cat(void);
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		Cat&			operator=(const Cat& cat);
/* **************************** MEMBER FUNCTIONS **************************** */
		virtual void	makeSound(void) const;
};

#endif
