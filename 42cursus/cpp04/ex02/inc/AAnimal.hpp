/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 22:57:56 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/14 23:16:06 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

class AAnimal
{
/**
 * Calling constructors or destructors of Abstract Classes may cause undefined
 * behaviour as they can not be instantiated. Due to this they are implemented
 * as protected to be used only in derived classes as it is mandatory.
*/
	protected:
		std::string	_type;
/* ****************************** CONSTRUCTORS ****************************** */
		AAnimal(void);
		AAnimal(const AAnimal& animal);

	public:
/* ******************************* DESTRUCTOR ******************************* */
		virtual ~AAnimal(void);
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		AAnimal&			operator=(const AAnimal& animal);
/* **************************** MEMBER FUNCTIONS **************************** */
		std::string		getType(void) const;
		virtual void	makeSound(void) const = 0;
};

#endif
