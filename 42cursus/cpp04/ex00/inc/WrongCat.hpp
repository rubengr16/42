/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 22:58:32 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/13 10:45:59 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
/* ****************************** CONSTRUCTORS ****************************** */
	private:
		WrongCat(std::string type);

	public:
		WrongCat(void);
		WrongCat(const WrongCat& wrongCat);
/* ******************************* DESTRUCTOR ******************************* */
		~WrongCat(void);
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		WrongCat&	operator=(const WrongCat& wrongCat);
/* **************************** MEMBER FUNCTIONS **************************** */
		void		makeSound(void) const;
};

#endif
