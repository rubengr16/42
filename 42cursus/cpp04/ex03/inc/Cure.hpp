/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 00:02:42 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/13 22:54:29 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "AMateria.hpp"

class	Cure: public AMateria
{
	public:
/* ****************************** CONSTRUCTORS ****************************** */
		Cure(void);
		Cure(const std::string& type);
		Cure(const Cure& cure);
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		Cure&				operator=(const Cure& cure);
/* ******************************* DESTRUCTOR ******************************* */
		~Cure(void);
/* **************************** MEMBER FUNCTIONS **************************** */
		virtual AMateria*	clone(void) const;
		virtual void		use(ICharacter& target);
};

#endif
