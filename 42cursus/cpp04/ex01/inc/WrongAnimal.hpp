/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 22:57:56 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/13 10:44:24 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	private:
		WrongAnimal(std::string type);

	protected:
		std::string	_type;

	public:
/* ****************************** CONSTRUCTORS ****************************** */
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal& wrongAnimal);
/* ******************************* DESTRUCTOR ******************************* */
		~WrongAnimal(void);
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		WrongAnimal&	operator=(const WrongAnimal& wrongAnimal);
/* **************************** MEMBER FUNCTIONS **************************** */
		std::string		getType(void) const;
		void			makeSound(void) const;
};

#endif
