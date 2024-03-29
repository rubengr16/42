/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 00:02:42 by rgallego          #+#    #+#             */
/*   Updated: 2023/12/02 13:59:36 by rgallego         ###   ########.fr       */
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
/* ******************************* DESTRUCTOR ******************************* */
		~Cure(void);
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		Cure&				operator=(const Cure& cure);
/* **************************** MEMBER FUNCTIONS **************************** */
		virtual AMateria*	clone(void) const;
		virtual void		use(ICharacter& target);
};

#endif
